function copyBash(btn) {
  const pre = btn.closest('.bash-block').querySelector('pre');
  navigator.clipboard.writeText(pre.innerText).then(() => {
    btn.textContent = '✓ zkopírováno';
    btn.classList.add('copied');
    setTimeout(() => { btn.textContent = 'kopírovat'; btn.classList.remove('copied'); }, 2000);
  });
}

// Active sidebar link on scroll
const sections = document.querySelectorAll('.lesson-sec');
const links    = document.querySelectorAll('aside .sidebar-link[data-target]');

const observer = new IntersectionObserver(entries => {
  entries.forEach(entry => {
    if (entry.isIntersecting) {
      const id = entry.target.id;
      links.forEach(l => l.classList.toggle('active', l.dataset.target === id));
    }
  });
}, { rootMargin: '-20% 0px -70% 0px' });

sections.forEach(s => observer.observe(s));
