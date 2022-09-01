#include <cstdio>
#include <iostream>

using namespace std;

#define endl '\n'
#define li long int

struct content{
    string name;
    int pos=0;
    int state = 1;
};

struct hashTable{
    int size = 101;
    int ocup = 0;
    content val[101];
};

li h(string key){
    int keySize = key.size();
    li idx = 0;

    for (int j=0; j<keySize; j++){
        idx += ((int)key[j]) * (j+1);
    }
    idx *= 19;
    return idx;
}

int hashKey(string key){

    li hashedIdx = h(key);

    hashedIdx = hashedIdx % 101;

    return hashedIdx;
}

int find(hashTable* hash, content value){
    

    int hashedIdx = hashKey(value.name);

    for (int j=0; j<20; j++){
        int aux = ((hashedIdx) + (j*j) + (23*j)) % 101;
        if(hash->val[aux].state == 1) return -1;
        if(hash->val[aux].state == -2) continue;
        if(hash->val[aux].name == value.name) return 1; 
    }

    return -1;
}
// state =  1 (LIVRE)
// state =  0 (OCUPADO)
// state = -2 (DELETADO)

int fixColision(hashTable* hash, content value, int idxPos){
    int newPos = idxPos;
    for(int j=0; j<20; j++){
        newPos = (idxPos+(j*j)+(23*j)) % 101;
        
        if (hash->val[newPos].state == 1 || hash->val[newPos].state == -2){
            return newPos;
        }
    }

    return -1;
}

void insert(hashTable* hash, content value){

    int idxPos = hashKey(value.name);
    int alreadyInTable = find(hash, value);
    int auxPos = idxPos;
    if(alreadyInTable == 1) return;
    auxPos = fixColision(hash, value, idxPos);
    if (auxPos == -1) return;
    // for(int j=0; j<20; j++){
    //     int auxIdx = (idxPos + (j*j) + (23*j)) % 101;
        
        if(hash->val[auxPos].state == 1 || hash->val[auxPos].state == -2){
            hash->ocup++;
            hash->val[auxPos].state = 0;
            hash->val[auxPos].name = value.name;
            hash->val[auxPos].pos = auxPos;
            return;
        }
    // }

    return;
}
// state =  1 (LIVRE)
// state =  0 (OCUPADO)
// state = -1 (DELETADO)
void remove(hashTable* hash, string name){
    int idx = hashKey(name);
    int auxIdx = idx;
    for(int j=0; j<20; j++){
        auxIdx = (idx+(j*j)+(23*j)) % 101;
        if(hash->val[auxIdx].name == name  && hash->val[auxIdx].state == 0){
            hash->val[auxIdx].state = -2;
            hash->ocup -= 1;
            return;
        }
    }
    return;
}

int main(){

    int loops, numInputs;
    char op[4], name[16];
    scanf("%d", &loops);

    for(int i=0; i<loops; i++){
        scanf("%d", &numInputs);
        hashTable hash;

        for(int j=0; j<numInputs; j++){
            scanf(" %[^:]", op);
            name [0] = '\0';
            scanf(":%[^\n]", name);

            if(op[0] == 'A'){

                content item;
                item.name = name;
                if(name[0] != '\0') insert(&hash, item);

            } else if (op[0] == 'D'){

                scanf(":%[^\n]", name);
                if(name[0] != '\0') remove(&hash, name);
            }
        }

        printf("%d\n", hash.ocup);
        //cout << hash.val[34].name << endl;
         for (int i=0; i<101; i++){
            if(hash.val[i].state == 0){
                cout << hash.val[i].pos << ":" << hash.val[i].name << endl;
            }
        }
    }
    return 0;
}
