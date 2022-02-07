# Maintainer: Zsolt Sajti <sajtizsolt@gmail.com>
pkgname=shivering-legion
pkgver=1.2
pkgrel=1
pkgdesc="Command line tool which allows Extreme Cooling on Lenovo Legion machines."
arch=("x86_64")
url="https://github.com/sajtizsolt/shivering-legion"
license=("MIT")
groups=()
depends=("glibc")
makedepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=("$url/archive/refs/tags/$pkgver.tar.gz")
noextract=()
sha256sums=('59bcf0ccef75ca09f93a01b0b7e6a4b5fa846ecf4a19fa587c36b458a0f34b7e')

build() {
  cd "$pkgname-$pkgver"

  make compile
}

package() {
  cd "$pkgname-$pkgver"
  mkdir "$pkgdir"/usr
  mkdir "$pkgdir"/usr/bin

  make DESTDIR="$pkgdir" install
}
