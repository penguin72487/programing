#include <iostream>

class BcNode{
    public: BcNode* op_Up;
    public: BcNode* op_Down;
    public: BcNode* op_Left;
    public: BcNode* op_Right;
    public: BcNode(){
        op_Up = this;
        op_Down = this;
        op_Left = this;
        op_Right = this;
    }
};

class MNode: public BcNode{
    public: int i_Row;
    public: int i_Col;
    public: MNode(int i_Row, int i_Col):
                BcNode(){
        this->i_Row = i_Row;
        this->i_Col= i_Col;
    }
};

template <class CL1>
class Ele: public MNode{
    public: CL1 CL1_V;
    public: Ele(int i_Row, int i_Col, CL1 CL1_V):
                MNode(i_Row, i_Col){
        this->CL1_V = CL1_V;
    }
};


template <class CL1>
class Matrix{
    public: MNode* op_Root;

    public: Matrix(int i_Row, int i_Col){
        if(i_Row <=0 && i_Col<=0){
            std::cerr<< "Row and Col errors in Matrix\n";
            exit(1);
        }

        op_Root = new MNode(i_Row, i_Col);
        BcNode* op_TmpMBc = static_cast<BcNode*>(op_Root);
        for(int i_Ct= 0; i_Ct < i_Col; i_Ct++){
            BcNode* op_MBc = new BcNode();
            op_TmpMBc->op_Right = op_MBc;
            op_MBc->op_Left = op_TmpMBc;
            op_TmpMBc = op_MBc;
        }
        op_TmpMBc->op_Right = static_cast<BcNode*>(op_Root);
        (static_cast<BcNode*>(op_Root))->op_Left = op_TmpMBc;


        op_TmpMBc = static_cast<BcNode*>(op_Root);
        for(int i_Ct= 0; i_Ct < i_Row; i_Ct++){
            BcNode* op_MBc = new BcNode();
            op_TmpMBc->op_Down = op_MBc;
            op_MBc->op_Up = op_TmpMBc;
            op_TmpMBc = op_MBc;
        }
        op_TmpMBc->op_Down = static_cast<BcNode*>(op_Root);
        (static_cast<BcNode*>(op_Root))->op_Up = op_TmpMBc;
    }

    public: ~Matrix(){
        int i_Ct= 0;
        int i_Raw =0;
        for(BcNode* op_S = (static_cast<BcNode*>(op_Root))->op_Right;
            op_S!= static_cast<BcNode*>(op_Root);
            ){
            BcNode* op_S2= op_S->op_Down;
            for(;op_S2!= op_S;){
                Ele<CL1>* op_EleTmp = static_cast<Ele<CL1>*>(op_S2);
                BcNode* op_ITmp = op_S2->op_Down;
                std::cout<< "Delete raw " << op_EleTmp->i_Row << "," << op_EleTmp->i_Col  <<" : "
                << op_EleTmp->CL1_V << "\n";
                delete op_EleTmp;
                ++i_Raw;
                op_S2= op_ITmp;
            }
            BcNode* op_Tmp = op_S->op_Right;
            delete op_S;
            std::cout<< "Delete the "<< ++i_Ct <<"th col\n";
            op_S= op_Tmp;
        }

        i_Ct = 0;
        for(BcNode* op_S = (static_cast<BcNode*>(op_Root))->op_Down;
            op_S!= static_cast<BcNode*>(op_Root);
            ){
            BcNode* op_Tmp = op_S->op_Down;
            delete op_S;
            std::cout<< "Delete the "<< ++i_Ct <<"th row\n";
            op_S= op_Tmp;
        }
        std::cout<< "Delete raws: "<< i_Raw << "\n";
        delete op_Root;
    }

    public: Ele<CL1>* fn_InsertEle(int i_RInd, int i_CInd, CL1 CL1_Value){
        Ele<CL1>* op_Ins = new Ele<CL1>(i_RInd, i_CInd, CL1_Value);
        BcNode* op_Ele = nullptr;
        op_Ele = fn_SrhPos(i_RInd, i_CInd, true);
        if(op_Ele == op_Ele->op_Right){//COM: Row root
            op_Ele->op_Left = static_cast<BcNode*>(op_Ins);
            op_Ele->op_Right = static_cast<BcNode*>(op_Ins);
            op_Ins->op_Left = op_Ele;
            op_Ins->op_Right = op_Ele;
        }
        else{
            BcNode* op_Tmp = op_Ele->op_Right;

            op_Ele->op_Right = static_cast<BcNode*>(op_Ins);
            op_Ins->op_Left = op_Ele;
            op_Ins->op_Right = op_Tmp;
            op_Tmp->op_Left = op_Ins;
        }

        op_Ele = fn_SrhPos(i_RInd, i_CInd, false);
        if(op_Ele == op_Ele->op_Down){//COM: Col root
            op_Ele->op_Up = static_cast<BcNode*>(op_Ins);
            op_Ele->op_Down = static_cast<BcNode*>(op_Ins);
            op_Ins->op_Up = op_Ele;
            op_Ins->op_Down = op_Ele;
        }
        else{
            BcNode* op_Tmp = op_Ele->op_Down;

            op_Ele->op_Down = static_cast<BcNode*>(op_Ins);
            op_Ins->op_Up = op_Ele;
            op_Ins->op_Down = op_Tmp;
            op_Tmp->op_Up = op_Ins;
        }

        return op_Ins;
    }

    public: void fn_TraceR(){
        BcNode* o_CtRRoot = op_Root->op_Down;
        for(;o_CtRRoot!= static_cast<BcNode*>(op_Root); o_CtRRoot=o_CtRRoot->op_Down){
            if(o_CtRRoot == o_CtRRoot->op_Right){
                for(int i_Ct=0;i_Ct < op_Root->i_Col; i_Ct++){
                    std::cout<<"0\t";
                }
                std::cout<< "\n";
            }
            else{
                BcNode* op_CtCol = o_CtRRoot->op_Right;
                for(int i_Ct=0;i_Ct < op_Root->i_Col; i_Ct++){
                    Ele<CL1>* op_CtColE = static_cast<Ele<CL1>*>(op_CtCol);
                    if(op_CtColE->i_Col == i_Ct){
                        std::cout<< op_CtColE->CL1_V<<"\t";
                        op_CtCol= op_CtCol->op_Right;
                    }
                    else{
                        std::cout<<"0\t";
                    }
                }
                std::cout<< "\n";
            }
        }
    }

    private: BcNode* fn_GetMNS(int i_Ind, bool b_IsRow =true){
        if(b_IsRow == true && i_Ind >= op_Root->i_Row){
            std::cerr<< "Error index\n";
            exit(1);
        }
        else if(b_IsRow == false && i_Ind >= op_Root->i_Col){
            std::cerr<< "Error index\n";
            exit(1);
        }

        BcNode* op_Curr = static_cast<BcNode*>(op_Root);
        if(b_IsRow == true){
            for(int i_Ct = 0; i_Ct <= i_Ind; i_Ct++){
                op_Curr = op_Curr->op_Down;
            }
        }
        else{
            for(int i_Ct = 0; i_Ct <= i_Ind; i_Ct++){
                op_Curr = op_Curr->op_Right;
            }
        }
        return op_Curr;
    }

    private: BcNode* fn_SrhPos(int i_RInd, int i_CInd, bool b_IsRowM = true){
        BcNode* op_RetNode = nullptr;
        if(b_IsRowM == true){
            op_RetNode = fn_GetMNS(i_RInd, b_IsRowM);
        }
        else{
            op_RetNode = fn_GetMNS(i_CInd, b_IsRowM);
        }

        BcNode* op_Curr = op_RetNode;
        if(b_IsRowM == true){
            for(int i_Ct = 0;
                    op_Curr!= op_Curr->op_Right;
                    op_Curr = op_Curr->op_Right){
                if(i_Ct == 0){
                    i_Ct++;
                    continue;
                }
                Ele<CL1>* op_Tmp = static_cast<Ele<CL1>*>(op_Curr);
                if(op_Tmp->i_Col > i_CInd){
                    op_RetNode = op_Curr->op_Left;
                    break;
                }
                else if(op_Tmp->i_Col < i_CInd && op_Curr->op_Right == op_RetNode){
                    op_RetNode = op_Curr;
                    break;
                }
            }
        }
        else{
            for(int i_Ct = 0;
                    op_Curr!= op_Curr->op_Down;
                    op_Curr = op_Curr->op_Down){
                if(i_Ct == 0){
                    i_Ct++;
                    continue;
                }
                Ele<CL1>* op_Tmp = static_cast<Ele<CL1>*>(op_Curr);
                if(op_Tmp->i_Row > i_CInd){
                    op_RetNode = op_Curr->op_Up;
                    break;
                }
                else if(op_Tmp->i_Row < i_CInd && op_Curr->op_Down == op_RetNode){
                    op_RetNode = op_Curr;
                    break;
                }
            }
        }
        return op_RetNode;
    }
};

int main(){
    Matrix<int> o_M(4,4);
    o_M.fn_InsertEle(0, 2, 11);
    o_M.fn_InsertEle(1, 0, 12);
    o_M.fn_InsertEle(2, 1, -4);
    o_M.fn_InsertEle(3, 3, -15);
    o_M.fn_TraceR();
    return 0;
}
