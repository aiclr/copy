# copy

copy with process bar

## cmake

> Specifying<sub>指定</sub> directories `cmake -B build -S .`
> > `-B` option that automatically creates the `build` directory. \
> > `-S` option specifies the source directory (where to search for a `CMakeLists.txt` file)
>
> build `cmake --build build` \
> install  `cmake --install build --prefix "/usr"`
> > `/usr/bin`、`/usr/lib`、`/usr/include`
>
> cpack `cmake --build build --target cpack`

## Archlinux PKGBUILD

> `mkdir -p ~/aur/copy` \
> `cp PKGBUILD ~/aur/copy` \
> `cd ~/aur/copy` \
> `makepkg -sirc` \
> `sudo pacman -Rs copy-git`
