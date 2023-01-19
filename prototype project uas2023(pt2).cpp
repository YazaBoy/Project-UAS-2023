#include<iostream>
#include<random>
#include<cstdlib>
#include<ctime>
using namespace std;
/*  Nama    : Ilyasa Nur
    Prodi   : Teknik Informatika 1A
    Tugas ke: PROJECT UAS2023
    Tanggal : 16-januari-2023*/

void HangmanGame(){
    const int max=6;
    const int mati=5;
    char kesulitan;
    string Hkalimat,Dkalimat,Pkata,hasilA,hasilB,sensor,ketebak,jawab;
    string hardcore[15]={"KELAPA","REXONA","DOMPET","PARFUM","KERBAU","SUMPIT","BERENANG","RANSEL","STROBERI","BERLIAN","CORONA","TELEVISI","AMBULANS","CRAYON","SAPIPERAH"};//daftar jawaban mode hardcore
    string deadly[15]={"TEHPUCUKHARUM","KOMPUTERJADUL","PISANGBUSUK","SUPERKOMPUTER","FOTOSINTESIS","LAPTOPGAMING","MASFAKSAINTEK","SIPUTLARICEPAT","BERLIANMAHAL","EMASMENGKILAP","KEBUNPADIPAKBUDI","TEKNIKINFORMATIKATHEBEST","HUJANASAMLAMBUNG","MIEGORENGBERKUAH","AYAMKAMPUNGBERANAK"};//daftar jawaban mode deadly
    int foul,gagal,wrong;
    //main menu
    mainmenu:
    jawab=jawab.size();
    cout<<"===Selamat datang di HANGMAN GAME===\nsemoga beruntung!\n====================\n";
    cout<<"Mulai game?(y/n)\n";
    cin>>jawab;
    if(jawab=="n"||jawab=="N"){
        goto end;
    }
    else if(jawab=="y"||jawab=="Y"){
        system("CLS");
        goto persiapan;
    }
    else{
        cout<<"Bukan pilihan\n";
        cout<<"Ulangi game?";
        cin>>jawab;
        if(jawab=="y"||jawab=="Y"){
            system("CLS");
            goto mainmenu;
        }
        else if(jawab=="n"||jawab=="N"){
            system("CLS");
            goto end;
    }
    }
    system("CLS");
    persiapan:
    system("CLS");
    jawab=jawab.size();
    cout<<"Pilih lawan\nA.Player\nB.Komputer\n";
    cin>>jawab;
    system("CLS");
    if(jawab=="a"||jawab=="A"||jawab=="b"||jawab=="B"){
        goto gamestrt;
    }
    else if(jawab!="a"||jawab!="A"||jawab=="b"||jawab=="B") {
        cout<<"Bukan pilihan\n";
        cout<<"ulangi(y/n)\n";
        cin>>jawab;
    if(jawab=="n"||jawab=="N"){
        goto end;
    }
    else if(jawab=="y"||jawab=="Y"){
        goto persiapan;
    }
}

    gamestrt:
    //persiapan game vs player
    system("CLS");
    if(jawab=="a"||jawab=="A"){
        //case 1 :vs player
        player:
        cout<<"Gunakan huruf kapital untuk KATA yang akan kamu pakai sebagai jawaban, dan pemain hanya memiliki 8 kesempatan menjawab salah!\nkalimat: ";
        cin>>Pkata;
        cout<<"Siap?(y/n)";
        cin>>jawab;
        if(jawab=="y"||jawab=="Y"){
        }
        else if(jawab=="n"||jawab=="N"){
            system("CLS");
            cout<<"ulangi atau keluar?\nY.ulangi\nN.keluar\n";
            cin>>jawab;
        while (jawab=="y"||jawab=="Y"){
            if(jawab=="y"||jawab=="Y"){
                system("CLS");
                goto player;
            }
            else if(jawab=="n"||jawab=="N"){
                goto end;
            }
            else{
                cout<<"bukan pilihan";
                cout<<"ulangi?";
                cin>>jawab;
                system("CLS");
            }
        }
        }
    else{
        system("CLS");
        cout<<"bukan pilihan\n";
        cout<<"siap atau keluar?(y/n)\n";
        cin>>jawab;
        if(jawab=="n"||jawab=="N"){
            goto end;
        }
    }
    system("CLS");
    sensor=string(Pkata.size(), '-');
    ketebak="";
    foul=0;
    //game vs player
    while(foul<max && sensor !=Pkata){
        cout<<"Kamu punya "<<(max-foul)<<" kesempatan menjawab salah\n";
        cout<<"====================\n";
        cout<<"Kamu sudah menebak dengan huruf "<<ketebak<<endl;
        cout<<"Huruf dalam kata yang sudah kamu tebak "<<sensor<<endl;
        //input tebakan
        char tebak;
        cout<<"Tebakanmu: ";
        cin>>tebak;
        tebak=toupper(tebak);
        system("CLS");
        //checkpoint pengecekan
        while(ketebak.find(tebak) != string::npos){
            cout<<"Kamu sudah menebak dengan huruf "<<tebak<<endl;
            cout<<"Tebakanmu:";
            cin>>tebak;
            tebak=toupper(tebak);
        }
        ketebak+=tebak;
        if(Pkata.find(tebak) !=string::npos){
            cout<<"Benar "<<tebak<<" adalah salah satu hurufnya\n";
            for(int i=0;i< Pkata.length();++i){
                if(Pkata[i]==tebak){
                    sensor[i]=tebak;
                }
            }
            system("CLS");
        }
        else {
            cout<<"Maaf tebakanmu salah\n";
            ++foul;
            system("CLS");
        }
    }
    }//break;
    else if(jawab=="b"||jawab=="B"){//vs com
        srand(time(0));
    //pilih kesulitan
        beware:
        cout<<"KAMU HANYA PUNYA 5 KALI KESEMPATAN MENJAWAB SALAH!\n";
        cout<<"Kamu siap?(y/n)";
        cin>>jawab;
        if(jawab=="n"||jawab=="N"){
            cout<<"Ulangi game?(y/n)";
            cin>>jawab;
            if(jawab=="y"||jawab=="Y"){
                system("CLS");
                goto beware;
            }
        else if(jawab=="n"||jawab=="N"){
            goto end;
        }
        }
    else if(jawab=="y"||jawab=="Y"){
        system("CLS");
        goto persiapan2;
    }
    else{
        rip:
        system("CLS");
        cout<<"Bukan pilihan\n";
        cout<<"ulangi?(y/n)";
        cin>>jawab;
        if(jawab=="y"||jawab=="Y"){
            system("CLS");
            goto beware;
        }
        else if(jawab=="n"||jawab=="N"){
            goto end;
        }
        else{
            goto rip;
        }
    }
    persiapan2:
    cout<<"Pilih kesulitan\nA.Hardcore\nB.Deadly\n";
    cin>>kesulitan;
    system("CLS");
    //game vs com
    if (kesulitan=='a'||kesulitan=='A'){
        string Hkalimat=hardcore[rand()%10];
        hasilA=Hkalimat;
        sensor=string(Hkalimat.size(), '-');
        ketebak="";
        gagal=0;
        while(gagal<mati && sensor !=Hkalimat){
            cout<<"Kamu punya "<<(mati-gagal)<<" kesempatan menjawab salah\n";
            cout<<"====================\n";
            cout<<"Kamu sudah menebak dengan huruf "<<ketebak<<endl;
            cout<<"Huruf dalam kata yang sudah kamu tebak "<<sensor<<endl;
            //input tebakan
            char tebak;
            cout<<"Tebakanmu: ";
            cin>>tebak;
            tebak=toupper(tebak);
            system("CLS");
            //checkpoint pengecekan
            while(ketebak.find(tebak) != string::npos){
                cout<<"Kamu sudah menebak dengan huruf "<<tebak<<endl;
                cout<<"Tebakanmu: ";
                cin>>tebak;
                tebak=toupper(tebak);
            }
        ketebak+=tebak;
        if(Hkalimat.find(tebak) !=string::npos){
            cout<<"Benar "<<tebak<<" adalah salah satu hurufnya\n";
            for(int a=0;a< Hkalimat.length();++a){
                if(Hkalimat[a]==tebak){
                    sensor[a]=tebak;
                }
            }
            system("CLS");
        }
        else {
            cout<<"Maaf tebakanmu salah\n";
            ++gagal;
            system("CLS");
        }
        }
    }
    else if(kesulitan=='b'||kesulitan=='B'){
        string Dkalimat=deadly[rand()%10];
        hasilB=Dkalimat;
        sensor=string(Dkalimat.size(), '-');
        ketebak="";
        wrong=0;
        while(wrong<mati && sensor !=Dkalimat){
            cout<<"Kamu punya "<<(mati-wrong)<<" kesempatan menjawab salah\n";
            cout<<"====================\n";
            cout<<"Kamu sudah menebak dengan huruf "<<ketebak<<endl;
            cout<<"Huruf dalam kata yang sudah kamu tebak "<<sensor<<endl;
        //input tebakan
        char tebak;
        cout<<"Tebakanmu: ";
        cin>>tebak;
        tebak=toupper(tebak);
        system("CLS");
        //checkpoint pengecekan
        while(ketebak.find(tebak) != string::npos){
            cout<<"Kamu sudah menebak dengan huruf "<<tebak<<endl;
            cout<<"Tebakanmu: ";
            cin>>tebak;
            tebak=toupper(tebak);
        }
        ketebak+=tebak;
        if(Dkalimat.find(tebak) !=string::npos){
            cout<<"Benar "<<tebak<<" adalah salah satu hurufnya\n";
            for(int b=0;b <Dkalimat.length();++b){
                if(Dkalimat[b]==tebak){
                    sensor[b]=tebak;
                }
            }
            system("CLS");
        }
        else {
            cout<<"Maaf tebakanmu salah\n";
            ++wrong;
            system("CLS");
        }
        }
    }
    else{
        cout<<"Bukan pilihan\n";
        cout<<"ulangi?(y/n)";
        cin>>jawab;
        if(jawab=="y"||jawab=="Y"){
            system("CLS");
            goto persiapan2;
        }
        else if (jawab=="n"||jawab=="N"){
            goto end;
        }
    }
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
        cout<<"KAMU BERHASIL!\n";
    }
    if(kesulitan=='a'||kesulitan=='A'){
        cout<<"Jawabannya adalah: "<<hasilA<<endl;
        cout<<"====================\n";
    }
    else if(kesulitan=='b'||kesulitan=='B'){
        cout<<"Jawabannya adalah: "<<hasilB<<endl;
        cout<<"====================\n";
    }
    else {
        cout<<"Jawabannya adalah: "<<Pkata<<endl;
        cout<<"====================\n";
    }
    //repeat
    cout<<"Ulangi game?";
    cin>>jawab;
        while(jawab != "n" && jawab != "N") {
            if(jawab == "y" || jawab == "Y") {
            system("CLS");
            goto mainmenu;
            } 
            else {
                system("CLS");
                cout<<"Bukan pilihan\n";
                cout<<"Ulangi game?:";
                cin>>jawab;
            }
        }
end:
system("CLS");
cout<<"====================\nTerimakasih sudah bermain\n====================";
}
int main(){
    HangmanGame();
    return 0;
}