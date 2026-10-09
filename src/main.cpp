#include <Arduino.h>
#include <string.h> //* strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //* atoi

void textoChar();
void textoString();

void setup()
{
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop() {}

void textoChar()
{
  //* Texto literal
  //* Use const char quando o texto nao será alterado
  const char cidade[] = "Sao Paulo";
  Serial.println(cidade);

  //* Descobrindo o tamanho do texto
  //* strlen conta quantos caracteres antes do '\0'
  int tamanhoTextoCidade = strlen(cidade);

  Serial.println("Comprimento do texto");
  Serial.println(tamanhoTextoCidade);

  //* Descobrindo o tamanho ocupado
  //* o sizeof() retornara um byte a mais que o comprimento por causa do '\0'

  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.println("Espaco utilizado");
  Serial.println(tamanhoVariavelCidade);

  //* o caractere \0 é colocado automaticamente quando escrevemos
  //* um texto entre " ".
  char vetorTexto[] = {'T', 'h', 'i', 'a', 'g', 'o', '\0'};
  Serial.println(vetorTexto);

  //=======================================Texto constante com char=========================================
  //* Comparar texto
  const char *cidade1 = "Sao Caetano";
  const char *cidade2 = "Sao Caetano";

  if (strcmp(cidade1, cidade2) == 0)
    Serial.println("Os textos sao iguais");

  else
    Serial.println("Os textos sao diferentes");

  //* strcmp analiza a ordem lexica das palavra, se a primeira palavra vem antes
  //* que a segunda o retorno será menos que zero, se a primeira vem após
  //* a segunda o retorno será maior que zero.

  //!=============================
  //! TEXTO EDITAVEL COM CHAR []
  //!=============================

  char nomeAluno[20] = "Thiagp";
  Serial.println(nomeAluno);

  //* Alterando caracteres individualmente
  nomeAluno[5] = 'o';
  Serial.println(nomeAluno);

  //* Copiando outro texto para dentro do vetor
  //! Cuidado: o vetor precisa ter espaco suficiente

  strcpy(nomeAluno, "Felipe");
  Serial.println(nomeAluno);

  //* Concatenando de texto ao final
  char frase[40] = "Ola ";
  strcat(frase, "Mundo");
  Serial.println(frase);

  //* procurando um caractere no texto
  //* Frase "Ola Mundo"

  char *posicaoLetra = strchr(frase, 'M');
  if (posicaoLetra != NULL)
  {
    Serial.println("Letra Encontrada");
    Serial.println(posicaoLetra);
  }
  else
  {
    Serial.println("Letra nao encontrada");
  }

  //*Convertendo texto numerico para uma inteiro
  char idadeTexto[] = "45"; // 52, 53, \0 na ASCII
  int idade = atoi(idadeTexto);
  Serial.println(idade);
  
}

void textoString()
{
  
    //* ============================================
    //* USADO String
    //* ============================================
  
    String nome = "Thiago";
    String curso = "Logica de Programacao";
    String mensagem = "Ola";
    
    //* Concatenando String
    mensagem = mensagem + "," + nome + "Bem-vindo ao curso de  " +  curso + ".";

    //*Tamanho da String
    int tamanhoMensagem = mensagem.length();
    Serial.print("Tamanho da String em letras:");
    Serial.println(tamanhoMensagem);

    //*acessando um caractere em uma posicao especifica
    char primeiraLetra = mensagem.charAt(0);
    Serial.print("Primeira letra: ");
    Serial.println(primeiraLetra);
    
    //* Também é possivel acessar com colchetes
    char segundaLetra = mensagem[1];
    Serial.println(segundaLetra);
    

    //* Procurando um texto dentro da String
    int posicaoTextoProcurado = mensagem.indexOf("curso");
    Serial.println(posicaoTextoProcurado);

    //*extraindo um texto dentro de uma String
    int inicioNomeCurso = posicaoTextoProcurado + 9 ; //* posicao da palavra curso + 9 caracteres
    Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1)); //* -1 tira o ponto final

    //* Substituindo um termo dentro da String
    mensagem.replace("Ola", "Oi tudo bom? ");
    Serial.println(mensagem);
    
    //* Convertendo para maiúsculas
    mensagem.toUpperCase();
    Serial.println(mensagem);
    
    //* Convertendo para maiúsculas
    mensagem.toLowerCase();
    Serial.println(mensagem);

    //*Convertendo texto numerico para inteiro
    String textoNumero("123");
    int numero = textoNumero.toInt();
    Serial.println(numero * 2);

    //* Verificando se a String está vazia
    String textoVazio = "";
    if(textoVazio.length() == 0) Serial.println("O texto está vazio");

    //* Convertendo String está vazia
    //* Isso é util quando alguma biblioteca espera texto  estilo C
    const char* textoComoChar = mensagem.c_str();
    Serial.println(textoComoChar);
    
    
    
    





    
}