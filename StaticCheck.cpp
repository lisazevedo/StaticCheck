// StaticCheck.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <string>

#include "LesAnalyzer.h"
#include "SintaxAnalyzer.h"
#include "StreamReader.h"
#include "StreamWriterLES.h"
#include "StreamWriterTAB.h"
#include "SymbolTab.h"
#include "Token.h"

using namespace std;

void test(list<string>::iterator &it) {
    advance(it, 1);
    std::cout << *it << std::endl;
}

int main()
{
    std::list<std::string> listOfStrs =
    { "First", "Sec", "Third", "Fourth", "Fifth", "Sixth" };
    /**** Finding nth element using std::advance() ******/
    // Find 3rd element from list
    // Create iterator pointing to first element
    std::list<std::string>::iterator it = listOfStrs.begin();
    // Advance the iterator by 2 positions,
    std::advance(it, 2);
    // Now iterator it points to 3rd element
    test(it);
    std::cout << "3rd element = " << *it << std::endl;
    std::advance(it, 2);
    std::cout << *it << std::endl;
    // Now iterator it points to 3rd element
    std::cout << "3rd element = " << *it << std::endl;
    /**** Finding nth element using std::next() ******/
    // Find 3rd element from list
    // It returns a new iterator pointing to n position after the
    // base iterator given as first argument
    auto it1 = std::next(listOfStrs.begin(), 2);
    std::cout << "3rd element = " << *it1 << std::endl;
    return 0;
    
  
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
