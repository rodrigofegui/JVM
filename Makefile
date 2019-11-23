###################
# Programas
###################
# Responsável por compilar a aplicação desenvolvida em C/C++
# COMP = gcc
COMP = g++
ASM_COMP = nasm
ASM_COMP2 = gcc
# Flags do compilador
# COMP_FLAGS = -g
COMP_FLAGS = -g -std=c++11
ASM_COMP_FLAGS = -f elf
ASM_OBJ_DEPENDENCIAS = asm/lfsr.o asm/driver_lfsr.c -m32 -lm
# Resposável pela análise estática do código C/C++
ESTATICO = cppcheck
# Flags para o estático
ESTATICO_FLAGS = --platform=unix64 --enable=warning,style,performance,portability,unusedFunction --language=c++
# Responsável pela análise dinâmica do programa
DINAMICO = valgrind
# Flags do analisador dinâmico
DINAMICO_FLAGS = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

###################
# Manipuladores de arquivos
###################
# Raiz do projeto
DIR_BASE = `pwd`
# Todos Arquivos-fonte .c a partir do diretório corrente
# DIR_FONTES = `find . -type f -iname *.c -print |  sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/ /g'`
DIR_FONTES = `find . -type f -iname *.cpp -print |  sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/ /g'`
DIR_ASM_FONTES = $(DIR_ASM)lfsr.asm
# Diretório dos arquivos objetos
DIR_OBJETOS = obj/
# Diretório dos arquivos necessários para o Assembly
DIR_ASM = asm/
# Arquivo executável
EXECUTAVEL = saida.out
# Arquivo de configuração do doxygen
DOC_CONFIG = doxyfile.conf

###################
# Constantes
###################
DESTAQUE = ************************************************

###################
# Flags padrões do executável
###################
# Modo de operação do executável
modo = e
# Arquivo a ser manipulado
arq1 = CasosTestes/double_aritmetica.class
arq2 = CasosTestes/ControladorMidi.class
arq3 = CasosTestes/ControladorEstoque.class
arq4 = CasosTestes/Instrumento.class
arq5 = CasosTestes/Pig.class
arq6 = CasosTestes/Outer.class
arq7 = CasosTestes/OtherClass.class
arq8 = CasosTestes/ThrowExcep.class
arqs = $(arq8)

###################
# Regras
###################
help:
	@echo "Usabilidade: make opcao [flags]"
	@echo ""
	@echo "Opções:"
	@echo "    limpar_obj        Apaga todos os arquivos objetos .o já gerados"
	@echo "    limpar_bin        Apaga o arquivo executável .out já gerado"
	@echo "    limpar            Apaga tantos os arquivos objetos quanto o executável"
	@echo "    doc               Gera a documentação do projeto"
	@echo "    estatico          Analisador estático recursivo sobre o diretório corrente"
	@echo "    objetos           Gera os arquivos objetos .o para todos os arquivos"
	@echo "                      .c encontrados recursivamente a partir do diretório corrente"
	@echo "    asm_obj			 Gera os arquivos objetos .o para todos os arquivos"
	@echo "                      .asm encontrados recursivamente a partir do diretório corrente"
	@echo "    compilar          Gera o arquivo executável"
	@echo "    asm_comp          Gera o arquivo executável para o código assembly"
	@echo "    executável        Executa o programa em si."
	@echo "                      Aceita as flags: <modo> e <arqs>"
	@echo "    asm_exe           Executa o programa assembly"
	@echo "    asm               Executa o ciclo completo para o programa assembly"
	@echo ""
	@echo "Flags:"
	@echo "    modo=e|i          Controle de como o programa tratará os arquivos .class:"
	@echo "                      e = leitor e exibidor <default>"
	@echo "                      i = leitor e interpretador"
	@echo "    arqs=arq1 arq2    Arquivos a serem manipulados pelo programa, separados por ' '"


limpar_obj:
	@echo "$(DESTAQUE)"
	@echo "A limpar o diretório de objetos..."

	@rm -rf $(DIR_OBJETOS)
	@mkdir $(DIR_OBJETOS)

	@echo "Limpeza concluída"
	@echo "$(DESTAQUE)\n"


limpar_bin:
	@echo "$(DESTAQUE)"
	@echo "A limpar o executável..."

	@rm -f $(EXECUTAVEL)

	@echo "Limpeza concluída"
	@echo "$(DESTAQUE)\n"


limpar: limpar_obj limpar_bin


doc:
	doxygen $(DOC_CONFIG)


estatico:
	@echo "${DESTAQUE}"
	@echo "Verificação estática sobre os arquivos:"
	@echo "${DIR_FONTES}\n"

	@$(ESTATICO) $(DIR_FONTES) $(ESTATICO_FLAGS)

	@echo "\n${DESTAQUE}\n"


objetos: estatico limpar_obj
	@echo "${DESTAQUE}"
	@echo "Gerando arquivos objetos a partir dos arquivos:"
	@echo "${DIR_FONTES}\n"

	@$(COMP) -c $(DIR_FONTES) $(COMP_FLAGS)
	@mv *.o $(DIR_OBJETOS)

	@echo "\nTodos foram movidos para o diretório:"
	@echo "'${DIR_OBJETOS}'"
	@echo "${DESTAQUE}\n"


asm_obj: limpar_obj
	@echo "${DESTAQUE}"
	@echo "Gerando arquivos objetos a partir dos arquivos:"
	@echo "${DIR_ASM_FONTES}"

	@$(ASM_COMP) $(ASM_COMP_FLAGS) $(DIR_ASM_FONTES) -i $(DIR_ASM) -d LINUX


compilar: limpar_bin objetos
	@echo "${DESTAQUE}"
	@echo "Compilando o projeto a partir dos arquivos:"
	@echo "'${DIR_OBJETOS}'"

	@$(COMP) obj/* -o $(EXECUTAVEL)

	@echo "\nExecutável gerado:"
	@echo "'$(EXECUTAVEL)'"
	@echo "${DESTAQUE}\n"


asm_comp: limpar_bin asm_obj
	@echo "${DESTAQUE}"
	@echo "Compilando o projeto a partir dos arquivos:"
	@echo "${DIR_OBJETOS}\n"

	$(ASM_COMP2) -o $(EXECUTAVEL) $(ASM_OBJ_DEPENDENCIAS)

	@echo "\nExecutável gerado:"
	@echo "'$(EXECUTAVEL)'"
	@echo "${DESTAQUE}\n"


executar:
	@clear
	@echo "${DESTAQUE}"
	@echo "Executando o arquivo:"
	@echo "'$(EXECUTAVEL)'"
	@echo "Com:"
	@echo "\t- Checagem de memória"
	@echo "\t- Busca de memória não liberada, relatório resumido"
	@echo "\t- Informe das perdas definitivas"
	@echo "\t- Busca pela origem de valores indefinido"
	@echo ""
	@$(DINAMICO) $(DINAMICO_FLAGS) ./$(EXECUTAVEL) -$(modo) --arqs $(arqs)

	@echo "\nAcabou a execução"
	@echo "${DESTAQUE}"


completo: compilar executar


asm: asm_obj asm_comp
	@./$(EXECUTAVEL)
