set number
set mouse=a
syntax on
set cc=80
let mapleader = " "
set splitbelow
set nocompatible
filetype off
filetype plugin indent on
nmap <leader>q :q<CR>
nmap <leader>w :w<CR>
nmap <leader>n : ! clear && norminette -R CheckForbiddenSourceHeader %<cr>
nmap <leader>c : ! clear && gcc -Wall -Wextra -Werror %  && ./a.out<cr>
let g:user_emmet_leader_key=','

call plug#begin()
Plug 'sheerun/vim-polyglot'
Plug 'mattn/emmet-vim'
Plug 'phanviet/vim-monokai-pro'
Plug 'cocopon/iceberg.vim'
Plug 'arcticicestudio/nord-vim'
Plug 'Badacadabra/vim-archery'
Plug 'kristijanhusak/vim-hybrid-material'
Plug 'scheakur/vim-scheakur'
Plug 'preservim/nerdtree'
call plug#end()

let NERDTreeShowBookmarks = 1
let NERDTreeShowHidden = 1
let NERDTreeShowLineNumbers = 0
let NERDTreeMinimalMenu = 1
let NERDTreeWinPos = "left"
let NERDTreeWinSize = 31
nmap <F2> :NERDTreeToggle<CR>
set termguicolors
colorscheme monokai_pro
hi Normal ctermbg=0
hi LineNr ctermbg=0
hi NonText ctermbg=0

