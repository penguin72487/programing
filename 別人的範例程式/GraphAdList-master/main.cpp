#include <algorithm>
#include <iostream>

struct Vet{
    public: char c_Name;
    public: Vet* clsp_Ptr;
};

struct AdList{
    public: Vet** cl2p_Ptr;
    public: char* cp_Name;
    public: int i_Size;

    public: AdList(char* cp_Name, int i_Size){
        cl2p_Ptr= new Vet*[i_Size];
        std::fill(cl2p_Ptr, cl2p_Ptr+ i_Size, nullptr);
        this->cp_Name = cp_Name;
        this->i_Size = i_Size;
    }

    public: bool fn_InsVet(char c_NameA, char c_NameB){
        int i_Ind = -1;
        for(int i_Ct= 0; i_Ct < i_Size; i_Ct++){
            if(c_NameA == cp_Name[i_Ct]){
                i_Ind = i_Ct;
                break;
            }
        }
        if(i_Ind == -1){
            return false;
        }

        Vet* o_Ele  = new Vet();
        o_Ele->c_Name = c_NameB;
        o_Ele->clsp_Ptr = cl2p_Ptr[i_Ind];
        cl2p_Ptr[i_Ind] = o_Ele;
        return 1;

    }

    public: ~AdList(){
        for(int i_Ct =0; i_Ct< i_Size; i_Ct++){
            for(Vet* o_Ele = cl2p_Ptr[i_Ct];
                o_Ele != nullptr;){
                Vet* o_Ele2  = o_Ele->clsp_Ptr;
                delete o_Ele;
                o_Ele = o_Ele2;
            }
        }
        delete [] cl2p_Ptr;
    }
};

int main(){
    char c_Arr[] = {'A', 'B', 'C', 'D', 'E'};
    int i_Size  = sizeof(c_Arr)/sizeof(char);
    AdList o_List = AdList(c_Arr, i_Size);
    o_List.fn_InsVet('A', 'A');
    o_List.fn_InsVet('A', 'B');
    o_List.fn_InsVet('A', 'C');
    o_List.fn_InsVet('A', 'D');

    for(Vet* o_Ele = (o_List.cl2p_Ptr)[0];
                o_Ele!= nullptr; o_Ele = o_Ele->clsp_Ptr){

        std::cout<< o_Ele->c_Name << " ";
    }

    return 0;
}
