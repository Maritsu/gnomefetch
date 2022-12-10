<img align="right" src="gnome.png" width=30%>

# gnomefetch
A joke fetch program that I made because I was *very* bored.

## Why?
Because why not?

## Dependencies
✨ NONE ✨ (obviously except for a compiler)

## Compiling
*An AUR package might be created for this in the future idk*

(literally copy-paste this)
```
git clone https://github.com/Maritsu/gnomefetch.git
cd gnomefetch
gcc -O3 gnomefetch.c -o gnomefetch
```

### Installation (add to PATH)
```
sudo install -m755 gnomefetch /usr/bin
```

### Uninstall (remove from PATH)
```
sudo rm /usr/bin/gnomefetch
```

## Usage
```
gnomefetch - a joke fetch program that I made because I was *very* bored.

USAGE
gnomefetch [args]
 -g	Use GNOME logo instead of actual gnome. Default if GNOME is detected as currently used DE.
 -n	Use an actual gnome. Used by default
 -h	Show help text
 -v	Show version
```
