#ifndef FAKULTAS_H_INCLUDED
#define FAKULTAS_H_INCLUDED
#include <iostream>
#define first(L1) L1.first
#define last(L1) L1.last
#define first(L2) L2.first
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
#define info(P) P->info 
using namespace std;

//Prodi Starts Here
struct Prodi{
    string kode;
    string namaFakultas;
    string namaProdi;
    Relasi relation;
};
typedef Prodi infotypeProdi;
typedef struct elmProdi *adrProdi;

typedef elmProdi {
    infotypeProdi info;
    adrProdi next, prev;
};
struct ListProdi{
    adrProdi first;
    adrProdi last;
};

//Prodi ends Here
struct Relasi
{
    Proposal proposal;
    string tanggalPengajuan;
    bool status;
};


//Proposal Start Here
struct Proposal
{
    string namaPenulis;
    string judulProposal;
};
typedef Proposal infotypeProposal;
typedef struct elmProposal *adrProposal;
typedef elmProposal {
    infotypeProposal info;
    adrProposal next;
};
struct ListProposal{
    adrProposal first;
};
//Proposal Ends Here

//Void And Functions
void createListProdi(ListProdi &L1);
void createNewElementProdi(infotypeProdi info, adrProdi &P);
void insertFirstProdi(List &L1, adrProdi P);
void deleteFirstProdi(List &L1, adrProdi &P);
void insertLastProdi(List &L1, adrProdi P);
void deleteLastProdi(List &L1, adrProdi &P);
void deleteAfterProdi(List &L1, adrProdi &prec,adrProdi &P);
void showAllProdi(ListProdi &L1);
void searchProdi(ListProdi &L1,string kodeProdi);
void showProdiWithProposal(ListProdi &L1,ListProposal &L2);
void deleteProdiWithRelation(ListProdi &L1, ListProposal &L2, string kodeProdi);


void createListProposal(ListProposal &L2);
void createNewElementProposal(infotypeProposal info,adrProposal &Q);
void addProposal(ListProdi &L1, ListProposal &L2, string kodeProdi, string namaProposal, string namaPenulis);
void searchProposal(ListProdi &L1,ListProposal &L2,string judul);

int countLulusProposalsFakultas(ListProdi &L1);

#endif