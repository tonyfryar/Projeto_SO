#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BlackGPIO/BlackGPIO.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;

#define PATH_ADC "/sys/bus/iio/devices/iio:device0/in_voltage"

int readAnalog(int number){
   stringstream ss;
   ss << PATH_ADC << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

int main(int argc, const char* argv[]){
   BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
   BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
   BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);
   BlackLib::BlackGPIO  button1(BlackLib::GPIO_115,BlackLib::input, BlackLib::SecureMode);

   cout << "### Inicializando o QUIZ ###" << endl;
   cout << "Pressione o botão para começar!" << endl;

   //Leitura da entrada analógica AIN1
   int contador = 0;
   bool acertou = true;
   //cout << "O valor lido foi " << valor << " [0 a 4095]." << endl;
   //cout << "O valor corresponde a " << (valor*1.8)/4096 << "Volts" << endl;
   
   while(acertou){

      while(button1.getNumericValue()){
      	int valor = readAnalog(1);
   		float resultado = (valor*1.8)/4096;   	 
        if (0 < resultado && resultado < 0.0039){
           cout << "Qual programa é reponsável por inicializar o sistema operacional ao ligar o computador?" << endl;
           string resposta;
           getline(cin,resposta);

        if (resposta.compare("bootloader") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
     else if (resultado >= 0.0039 && resultado < 0.020){
        cout << "Como é chamado o kernel onde o SO roda no userspace (fora do kernel space)?" << endl;
        string resposta;
        getline(cin,resposta);

        if(resposta.compare("Microkernel") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
      }
     else if (resultado >= 0.02 && resultado < 0.09){
        cout << "Qual o comando para desligar a BBB?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("shutdown -h now") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
     else if (resultado >= 0.09 && resultado < 0.15){
        cout << "Qual o comando para compilação cruzada?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("arm-linux-gnueabihf-g++ -std=c++11 -o exe main.cpp") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
        }
     }
     else if (resultado >= 0.15 && resultado < 0.5){
        cout << "Qual o comando para compilação cruzada (sem o executável e os arquivos .cpp)?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("arm-linux-gnueabihf-g++ -std=c++11 -o") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
     else if (resultado >= 0.5 && resultado < 0.9){
        cout << "Qual a limitação de voltagem das entradas analógicas da BBB?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("1.8") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
     else if (resultado >= 0.9 && resultado < 1.05){
        cout << "O fotoresistor (LDR) iluminado apresenta voltagem mais próximo de 1.8V ou 0V?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("1.8V") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
     else if (resultado >= 1.05 && resultado < 1.09){
        cout << "Qual o comando shell pra cópia segura ssh?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("scp") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
     else if (resultado >= 1.09 && resultado < 1.5){
        cout << "Como são conhecidas as chamadas de sistema de acesso aos recurso de máquina?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("system calls") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
     else if (resultado >= 1.5){
        cout << "Qual o melhor professor do IMD?" << endl;
        string resposta;
        getline(cin,resposta);

        if (resposta.compare("Ivanovitch") == 0){
           //chamar função LED verde
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          cout<<"Para pular para a próxima pergunta gire o potenciômetro e em seguida pressione o botão."<<endl;
          contador++;
        }
        else{
           //Chama função LED vermelho
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          sleep(3);
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          acertou = false;
          if(contador < 2){
            cout<<"Você precisa estudar um pouco mais...\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 4){
            cout<<"Quase lá... Estude um pouco mais.\n\nATÉ BREVE!!"<<endl;
          }
          else if(contador < 6){
            cout<<"Você foi muito bem! Continue assim!!"<<endl;
          }
          else{
            cout<<"Parabéns! Você está no nível Ivanovitch de aprendizado"<<endl;
          }
        }
     }
  }
}
   return 0;
}
