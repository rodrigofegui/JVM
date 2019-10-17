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
