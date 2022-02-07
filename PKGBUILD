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
sha256sums=(
  '41e422a5b9bb81e599fb3a192e6ee5ae43326ac44b2a81004d73d08262f072c3',
  'd3e2884b44eae8ced801b099b9d47f5a1f7ff5a7fc39f3b5aa4bdf8b9c59e0dd'
)

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
