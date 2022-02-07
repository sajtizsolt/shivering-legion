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
sha256sums=('5fd3cadd64f387749d511399de3e85cbe1c51f36aedd7fcd72c1eca3b7dcec68')

build() {
  cd "$pkgname-$pkgver"

  make compile
}

package() {
  cd "$pkgname-$pkgver"
  mkdir "$pkgdir"/usr/bin
  
  make DESTDIR="$pkgdir" install
}
