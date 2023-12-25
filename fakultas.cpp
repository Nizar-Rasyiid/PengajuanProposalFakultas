#include "fakultas.h"

void createListProdi(ListProdi &L1){
    first(L1) = NULL;
    last(L1) = NULL;
}
void createNewElementProdi(infotypeProdi info, adrProdi &P){
    P = new elmProdi;
    info(P) = info;
    next(P) = NULL;
}
void insertFirstProdi(ListProdi &L1, adrProdi &P){
    if (first(L1) == NULL){ 
    first(L1) = P;
    last(L1) = P;
    } else {
        next(P) = first(L1);
        prev(first(L1)) = P;
        first(L1) = P;
    } 
}
void insertLastProdi(ListProdi &L1,adrProdi &P){
    if (first(L1) == NULL && last(L1) == NULL){
        first(L1) = P;
        last(L1) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    } 
}

void deleteFirstProdi(List &L1, adrProdi &P){
    P = first(L1);
    if (first(L1) == last(L1)) {
        first(L1) = NULL;
        last(L1) = NULL;
    }else {
        first(L1) =  next(P);
        prev(first(L1)) = NULL;
        next(P) = NULL;
    }
}
void deleteLastProdi(List &L1,adrProdi &P){
        P = last(L1);
    if (first(L1) == last(L1)) {
        first(L1) = NULL;
        last(L1) = NULL;
    }else {
        last(L1) = prev(P);
        next(last(L1)) = NULL;
        prev(P) = NULL;
    }
}
void deleteAfterProdi(List &L1,adrProdi &prec,adrProdi &P){
        P = next(prec);
    if (next(P) != NULL) {
        next(prec) = next(P);
        prev(next(P)) = prec;
        next(P) = NULL;
        prev(P) = NULL;
    }else {
        deleteLastProdi(L1,P);
    }
}
void showAllProdi(ListProdi &L1) {
    adrProdi P = first(L1);
    cout << "List of Prodi:" << endl;
    while (P != NULL) {
        cout << "Kode: " << info(P).kode << endl;
        cout << "Nama Fakultas: " << info(P).namaFakultas << endl;
        cout << "Nama Prodi: " << info(P).namaProdi << endl;
        cout << "-----------------------" << endl;
        P = next(P);
    }
    cout << endl;
}

void searchProdi(ListProdi &L1, string kodeProdi) {
    adrProdi P = first(L1);
    bool found = false;
    while (P != NULL) {
        if (info(P).kode == kodeProdi) {
            found = true;
            cout << "Prodi found:" << endl;
            cout << "Kode: " << info(P).kode << endl;
            cout << "Nama Fakultas: " << info(P).namaFakultas << endl;
            cout << "Nama Prodi: " << info(P).namaProdi << endl;
            cout << "Related Proposals:" << endl;
            adrProposal Q = info(P).relation.proposal;
            while (Q != NULL) {
                cout << "- Nama Penulis: " << info(Q).namaPenulis << endl;
                cout << "  Judul Proposal: " << info(Q).judulProposal << endl;
                Q = next(Q);
            }

            cout << "-----------------------" << endl;
            break; 
        }
        P = next(P);
    }

    if (!found) {
        cout << "Prodi with kode " << kodeProdi << " not found." << endl;
    }
}

void showProdiWithProposal(ListProdi &L1,ListProposal &L2){
    adrProdi P = first(L1);
    cout << "Prodi with Proposals:" << endl;
    while (P != NULL) {
        if (info(P).relation.proposal != NULL) {
            cout << "Kode: " << info(P).kode << endl;
            cout << "Nama Fakultas: " << info(P).namaFakultas << endl;
            cout << "Nama Prodi: " << info(P).namaProdi << endl;
            cout << "Related Proposals:" << endl;
            adrProposal Q = info(P).relation.proposal;
            while (Q != NULL) {
                cout << "- Nama Penulis: " << info(Q).namaPenulis << endl;
                cout << "  Judul Proposal: " << info(Q).judulProposal << endl;
                Q = next(Q);
            }
            cout << "-----------------------" << endl;
        }
        P = next(P);
    }
    cout << endl;
}
void deleteProdiWithRelation(ListProdi &L1, ListProposal &L2, string kodeProdi) {
    adrProdi P = first(L1);
    while (P != NULL) {
        if (info(P).kode == kodeProdi) {
            adrProdi tempProdi = P;
            P = next(P);
            adrProposal Q = first(L2);
            while (Q != NULL) {
                if (info(Q).kode == kodeProdi) {
                    adrProposal tempProposal = Q;
                    Q = Q->next;
                    delete tempProposal;
                } else {
                    Q = Q->next;
                }
            }
            if (tempProdi == first(L1)) {
                deleteFirstProdi(L1, tempProdi);
            } else if (tempProdi == last(L1)) {
                deleteLastProdi(L1, tempProdi);
            } else {
                adrProdi prevProdi = prev(tempProdi);
                deleteAfterProdi(L1, prevProdi, tempProdi);
            }
        } else {
            P = next(P);
        }
    }
}
int countLulusProposalsFakultas(ListProdi &L1) {
    int count = 0;
    adrProdi P = first(L1);

    while (P != NULL) {
        adrProposal Q = info(P).relation.proposal;
        while (Q != NULL) {
            if (info(P).relation.status){
                count++;
            }
            Q = next(Q);
        }
        P = next(P);
    }
    return count;
}



void createListProposal(ListProposal &L2){
    first(L2) = NULL;
}
void searchProposal(ListProdi &L1, ListProposal &L2, string judul) {
    adrProdi P = first(L1);
    while (P != NULL) {
        adrProposal Q = info(P).relation.proposal;
        while (Q != NULL) {
            if (Q->info.judulProposal == judul) {
                cout << "Proposal found:" << endl;
                cout << "Nama Penulis: " << Q->info.namaPenulis << endl;
                cout << "Judul Proposal: " << Q->info.judulProposal << endl;
                cout << "Fakultas: " << info(P).namaFakultas << endl;
                cout << "Prodi: " << info(P).namaProdi << endl;
                cout << "Status: " << (info(P).relation.status ? "Lulus" : "Tidak Lulus") << endl;
                cout << "-----------------------" << endl;
            }
            Q = next(Q);
        }
        P = next(P);
    }

    cout << "Proposal with title \"" << judulProposal << "\" not found." << endl;
}


void createNewElementProposal(infotypeProposal info,adrProposal &Q){
    Q = new elmProposal;
    info(Q).namaPenulis = info.namaPenulis;
    info(Q).judulProposal = info.judulProposal;
    next(Q) = NULL;
}
void addProposal(ListProdi &L1, ListProposal &L2, string kodeProdi, string namaProposal, string namaPenulis){
    
}