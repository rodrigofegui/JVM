## JVM

Leitor e exibidor, e futuro interpretador, de arquivos .class

## Ferramentas

Sendo um código desenvolvido em C/C++ o analisador estático é o [CppCheck](https://github.com/danmar/cppcheck) na versão 1.89 (a mais recente até o momento), podendo ser instalado, em Linux, a partir dos comandos:

```
git clone git://github.com/danmar/cppcheck.git
cd cppcheck/
# Substituir pela mais recente
git checkout 1.89
make MATCHCOMPILER=yes FILESDIR=/usr/share/cppcheck HAVE_RULES=yes CXXFLAGS="-O2 -DNDEBUG -Wall -Wno-sign-compare -Wno-unused-function"
sudo FILESDIR=/usr/share/cppcheck make install
# Testando se foi instalado
cppcheck --version
```

Enquanto que para o analisador dinâmico, é utilizado o [Valgrind](http://www.valgrind.org/) na versão 3.15.0 (a mais recente até o momento), podendo ser instalado, em Linux, a partir dos comandos:

```
wget https://sourceware.org/pub/valgrind/valgrind-3.15.0.tar.bz2
tar -jxvf valgrind-3.15.0.tar.bz2
cd valgrind-3.15.0/
./configure
make
sudo make install
# Testando se foi instalado
valgrind --version
```

O Leitor/Exibidor utilizado foi o [jclasslib](https://github.com/ingokegel/jclasslib/releases/tag/5.3.2) na versão 5.3.2 (a mais recente no início do projeto), para poder comparar com o sistema desenvolvido.


## Trabalhos em Assembly

O montador assembly utilizado é o [NASM](https://www.nasm.us/) na versão [2.14.03rc2](https://www.nasm.us/pub/nasm/releasebuilds/2.14.03rc2/) (a mais recente até o momento). Além disso faz uso de bibliotecas desenvolvidas pelo [Paul Carter](https://pacman128.github.io/pcasm/), adquiridas a partir de seus respectivos exemplos aos sistemas operacionais.

Ao executar programas de 32-bits em máquina de 64-bits com o gcc, pelo menos, é preciso instalar um plugin de multiplaforma: multilib; que pode ser instalado, em Linux, a partir do comando: `sudo apt-get install gcc-multilib`.

Dessa forma, para executar um programa desejado é preciso seguir os comandos:

```
# Linux
nasm -f elf prog.asm
gcc -o prog prog.o driver.c asm_io.o -m32

# Windows
nasm -f win32 prog.asm
gcc -o prog prog.obj driver.c asm_io.obj -m32
```
