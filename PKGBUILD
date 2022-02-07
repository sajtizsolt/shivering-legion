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
source=("$url/archive/refs/tags/$pkgname-$pkgver.tar.gz")
noextract=()
sha256sums=('20619e6100fcad8e1dd3a3ca188bdd142862f7a2833ba29326a97af67e36847c')

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
