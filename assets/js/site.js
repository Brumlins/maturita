// Topology panel
function toggleTopo() {
  const panel = document.getElementById('topo-panel');
  const btn   = panel.querySelector('.topo-toggle');
  const isNowCollapsed = panel.classList.toggle('collapsed');
  btn.textContent = isNowCollapsed ? '+' : '−';
}

// Copy IOS command block
function copyCmd(btn) {
  const pre = btn.closest('.ios-block').querySelector('pre');
  navigator.clipboard.writeText(pre.innerText).then(() => {
    btn.textContent = '✓ zkopírováno';
    btn.classList.add('copied');
    setTimeout(() => { btn.textContent = 'kopírovat'; btn.classList.remove('copied'); }, 2000);
  });
}

// Progress checkboxes — persist via localStorage
const STORAGE_KEY = 'site-progress-' + location.pathname;

function initProgress() {
  const saved = JSON.parse(localStorage.getItem(STORAGE_KEY) || '{}');
  document.querySelectorAll('.check-item').forEach(item => {
    const id = item.dataset.task;
    if (saved[id]) item.classList.add('done');
    item.addEventListener('click', () => toggleTask(item));
  });
  updateProgress();
}

function toggleTask(item) {
  item.classList.toggle('done');
  const saved = JSON.parse(localStorage.getItem(STORAGE_KEY) || '{}');
  saved[item.dataset.task] = item.classList.contains('done');
  localStorage.setItem(STORAGE_KEY, JSON.stringify(saved));
  updateProgress();
}

function updateProgress() {
  const items = document.querySelectorAll('.check-item');
  const done  = document.querySelectorAll('.check-item.done').length;
  const fill  = document.querySelector('.progress-fill');
  const label = document.querySelector('.progress-count');
  if (fill)  fill.style.width = items.length ? (done / items.length * 100) + '%' : '0%';
  if (label) label.textContent = done + ' / ' + items.length;
}

// Active sidebar link on scroll
const tasks = document.querySelectorAll('.task');
const links = document.querySelectorAll('.sidebar-link[data-target]');

const observer = new IntersectionObserver(entries => {
  entries.forEach(entry => {
    if (entry.isIntersecting) {
      const id = entry.target.id;
      links.forEach(l => l.classList.toggle('active', l.dataset.target === id));
    }
  });
}, { rootMargin: '-20% 0px -70% 0px' });

tasks.forEach(t => observer.observe(t));

document.addEventListener('DOMContentLoaded', initProgress);
