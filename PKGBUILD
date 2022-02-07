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
sha256sums=('c825a8bf091a47b0240f96e0554e119ab87e20a1003ef5a2a483473aa3fda4ae')

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
