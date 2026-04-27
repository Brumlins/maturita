function showSchema(idx) {
  document.querySelectorAll('.schema-img').forEach((img, i) => img.classList.toggle('active', i === idx));
  document.querySelectorAll('.schema-tab').forEach((tab, i) => tab.classList.toggle('active', i === idx));
  // If panel is collapsed, open it when user explicitly picks a tab
  const panel = document.getElementById('schema-panel');
  if (panel.classList.contains('collapsed')) toggleSchema();
}

function toggleSchema() {
  const panel = document.getElementById('schema-panel');
  const btn   = panel.querySelector('.schema-toggle');
  const isNowCollapsed = panel.classList.toggle('collapsed');
  btn.textContent = isNowCollapsed ? '+' : '−';
}

function copyCode(btn) {
  const pre = btn.closest('.code-block').querySelector('pre');
  navigator.clipboard.writeText(pre.innerText).then(() => {
    btn.textContent = '✓ zkopírováno';
    btn.classList.add('copied');
    setTimeout(() => { btn.textContent = 'kopírovat'; btn.classList.remove('copied'); }, 2000);
  });
}

// Highlight active sidebar link while scrolling
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
