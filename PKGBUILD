# https://wiki.archlinux.org/title/VCS_package_guidelines

# Maintainer: bougainvilleas <bougainvilleas@qq.com>
#Suffix pkgname with -cvs, -svn, -hg, -darcs, -bzr, -git etc. unless the package fetches a specific release
pkgname=copy-git
# --holdver can be used to prevent makepkg from updating the pkgver
pkgver=0.0.0.r2.g8adeb41
pkgrel=1
pkgdesc="cp with progress bar"
arch=('x86_64')
url="https://bougainvilleas.github.io/lotus"
license=('GPL-3.0')
groups=('bougainvilleas')
depends=()
makedepends=('git') # 'bzr', 'git', 'mercurial' or 'subversion'
provides=("${pkgname%-GIT}")
conflicts=("${pkgname%-GIT}")
replaces=()
backup=()
options=()
install=
source=("${pkgname%-GIT}::git+https://github.com/bougainvilleas/copy.git#branch=main")
noextract=()
md5sums=('SKIP')

# --holdver can be used to prevent makepkg from updating the pkgver
pkgver() {
	cd "$srcdir/${pkgname%-GIT}"
  ( set -o pipefail
    git describe --long --abbrev=7 2>/dev/null | sed 's/\([^-]*-g\)/r\1/;s/-/./g' ||
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"
  )
  # tag
	# printf "%s" "$(git describe --long | sed 's/\([^-]*-\)g/r\1/;s/-/./g')"
  # no tag
  # printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"
}

# prepare() {
	# cd "$srcdir/${pkgname%-GIT}"
	# patch -p1 -i "$srcdir/${pkgname%-GIT}.patch"
# }

build() {
	cmake -B build -S "$srcdir/${pkgname%-GIT}"
  cmake --build build
}

# check() {
	# cd "$srcdir/${pkgname%-GIT}"
	# make -k check
# }

package() {
	# install 会安装到 "$pkgdir/usr" 即系统/usr/
	# 								"$pkgdir/usr/usr" 即系统/usr/local/
	cmake --install build --prefix "$pkgdir/usr"
}
