#include<iostream>
#include<random>
#include<cstdlib>
#include<ctime>
using namespace std;
/*  Nama    : Ilyasa Nur
    Prodi   : Teknik Informatika 1A
    Tugas ke: PROJECT UAS2023
    Tanggal : 13-januari-2023*/

int main(){
    const int max=8;
    const int mati=5;
    string menu,Hkalimat,Dkalimat,ready,kesulitan,Pkata,persiapan,hasilA,hasilB,sensor,ketebak;
    string hardcore[10]={"KELAPA","REXONA","DOMPET","PARFUM","KERBAU","SUMPIT","BERENANG","RANSEL","STROBERI","BERLIAN"};//daftar jawaban mode hardcore
    string deadly[10]={"TEHPUCUKHARUM","KOMPUTERJADUL","PISANGBUSUK","SUPERKOMPUTER","FOTOSINTESIS","LAPTOPGAMING","MASFAKSAINTEK","SIPUTLARICEPAT","BERLIANMAHAL","EMASMENGKILAP"};//daftar jawaban mode deadly
    int foul,musuh,gagal,wrong;
    //main menu
    mainmenu:
    cout<<"selamat datang di HANGMAN GAME. semoga beruntung!\n";
    cout<<"mulai game?(y/n)\n";
    cin>>menu;
    if(menu=="n"||menu=="N"){
        cout<<"terimakasih sudah berkunjung";
        return 0;
    }
    system("CLS");
    persiapan:
    cout<<"pilih lawan\n1.player\n2.komputer\n";
    cin>>musuh;
    //persiapan game vs player
    switch (musuh){
        case 1 ://vs player
        cout<<"gunakan huruf kapital untuk KATA yang akan kamu pakai sebagai jawaban, dan pemain hanya memiliki 8kesempatan menjawab salah!\nkalimat: ";
        cin>>Pkata;
        cout<<"siap?(y/n)";
        cin>>ready;
        if(ready=="n"||ready=="N"){
            cout<<"ulangi game?(y/n)";
            cin>>persiapan;
                if(persiapan=="y"||persiapan=="Y"){
                system("CLS");
                goto persiapan;
            }
        else if(persiapan=="n"||persiapan=="N"){
            system("CLS");
            cout<<"====================\nterimakasih sudah bermain\n====================";
            return 0;
        }
    }
    system("CLS");
    sensor=string(Pkata.size(), '-');
    ketebak="";
    foul=0;
    //game vs player
    while(foul<max && sensor !=Pkata){
        cout<<"kau punya "<<(max-foul)<<" kesempatan menjawab salah\n";
        cout<<"====================\n";
        cout<<"kamu sudah menebak huruf "<<ketebak<<endl;
        cout<<"kalimat yang sudah kamu tebak "<<sensor<<endl;
        //input tebakan
        char tebak;
        cout<<"tebak kalimat: ";
        cin>>tebak;
        tebak=toupper(tebak);
        system("CLS");
        //checkpoint pengecekan
        while(ketebak.find(tebak) != string::npos){
            cout<<"kamu sudah menebak dengan huruf "<<tebak<<endl;
            cout<<"tebak kalimat :";
            cin>>tebak;
            tebak=toupper(tebak);
        }
        ketebak+=tebak;
        if(Pkata.find(tebak) !=string::npos){
            cout<<"benar "<<tebak<<" adalah hurufnya\n";
            for(int i=0;i< Pkata.length();++i){
                if(Pkata[i]==tebak){
                    sensor[i]=tebak;
                }
            }
            system("CLS");
        }
        else {
            cout<<"maaf tebakanmu salah\n";
            ++foul;
            system("CLS");
        }
    }
    break;
    case 2://vs com
    srand(time(0));
    //pilih kesulitan
    cout<<"KAMU HANYA PUNYA 5 KALI KESEMPATAN MENJAWAB SALAH!\n";
    cout<<"kamu siap?(y/n)";
    cin>>ready;
    if(ready=="n"||ready=="N"){
        cout<<"ulangi game?(y/n)";
        cin>>persiapan;
        if(persiapan=="y"||persiapan=="Y"){
            system("CLS");
            goto persiapan2;
        }
        else if(persiapan=="n"||persiapan=="N"){
            system("CLS");
            cout<<"====================\nterimakasih sudah bermain\n====================";
            return 0;
        }
    }
    persiapan2:
    cout<<"pilih kesulitan\na.hardcore\nb.deadly\n";
    cin>>kesulitan;
    system("CLS");
    //game vs com
    if (kesulitan=="a"||kesulitan=="A"){
        string Hkalimat=hardcore[rand()%10];
        hasilA=Hkalimat;
        sensor=string(Hkalimat.size(), '-');
        ketebak="";
        gagal=0;
        while(gagal<mati && sensor !=Hkalimat){
            cout<<"kau punya "<<(mati-gagal)<<" kesempatan menjawab salah\n";
            cout<<"====================\n";
            cout<<"kamu sudah menebak huruf "<<ketebak<<endl;
            cout<<"kalimat yang sudah kamu tebak "<<sensor<<endl;
            //input tebakan
            char tebak;
            cout<<"tebak kalimat: ";
            cin>>tebak;
            tebak=toupper(tebak);
            system("CLS");
            //checkpoint pengecekan
            while(ketebak.find(tebak) != string::npos){
            cout<<"kamu sudah menebak dengan huruf "<<tebak<<endl;
            cout<<"tebak kalimat :";
            cin>>tebak;
            tebak=toupper(tebak);
        }
        ketebak+=tebak;
        if(Hkalimat.find(tebak) !=string::npos){
            cout<<"benar "<<tebak<<" adalah hurufnya\n";
            for(int a=0;a< Hkalimat.length();++a){
                if(Hkalimat[a]==tebak){
                    sensor[a]=tebak;
                }
            }
            system("CLS");
        }
        else {
            cout<<"maaf tebakanmu salah\n";
            ++gagal;
            system("CLS");
        }
    }
    }
    else if(kesulitan=="b"||kesulitan=="B"){
        string Dkalimat=deadly[rand()%10];
        hasilB=Dkalimat;
        sensor=string(Dkalimat.size(), '-');
        ketebak="";
        wrong=0;
        while(wrong<mati && sensor !=Dkalimat){
        cout<<"kamu punya "<<(mati-wrong)<<" kesempatan menjawab salah\n";
        cout<<"====================\n";
        cout<<"kamu sudah menebak huruf "<<ketebak<<endl;
        cout<<"kalimat yang sudah kamu tebak "<<sensor<<endl;
        //input tebakan
        char tebak;
        cout<<"tebak kalimat: ";
        cin>>tebak;
        tebak=toupper(tebak);
        system("CLS");
        //checkpoint pengecekan
        while(ketebak.find(tebak) != string::npos){
            cout<<"kamu sudah menebak dengan huruf "<<tebak<<endl;
            cout<<"tebak kalimat :";
            cin>>tebak;
            tebak=toupper(tebak);
        }
        ketebak+=tebak;
        if(Dkalimat.find(tebak) !=string::npos){
            cout<<"benar "<<tebak<<" adalah hurufnya\n";
            for(int b=0;b< Dkalimat.length();++b){
                if(Dkalimat[b]==tebak){
                    sensor[b]=tebak;
                }
            }
            system("CLS");
        }
        else {
            cout<<"maaf tebakanmu salah\n";
            ++wrong;
            system("CLS");
        }
    }
    }
    break;
    }
    //shutdown
    if(foul==max){
        cout<<"YOU'RE DEAD\n";
    }
    else if(gagal==mati){
        cout<<"YOU'RE DEAD\n";
    }
    else if(wrong==mati){
        cout<<"YOU'RE DEAD\n";
    }
    //win
    else{
        cout<<"kamu berhasil\n";
    }
    if(kesulitan=="a"||kesulitan=="A"){
    cout<<"kalimatnya adalah: "<<hasilA<<endl;}
    else if(kesulitan=="b"||kesulitan=="B"){
    cout<<"kalimatnya adalah: "<<hasilB<<endl;}
    else {
    cout<<"kalimatnya adalah: "<<Pkata<<endl;}
    //repeat
    cout<<"ulangi game?";
    cin>>ready;
        while(ready != "n" && ready != "N") {
        if(ready == "y" || ready == "Y") {
            system("CLS");
            goto mainmenu;
            } else {
                cout<<"bukan pilihan\n";
                cout<<"ulangi game?:";
                cin>>ready;
                }
}
cout<<"====================\nterimakasih sudah bermain\n====================";
return 0;

}