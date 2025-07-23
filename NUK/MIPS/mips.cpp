#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int IF_PCSrc;
int EX_ALUOP0, EX_ALUOP1, EX_RegDst, EX_ALUSrc, EX_Branch, EX_MemRead, EX_MemWrite, EX_RegWrite, EX_MemtoReg, rs, rt, rd, sign_extend;
int MEM_Branch, MEM_MemRead, MEM_MemWrite, MEM_RegWrite, MEM_MemtoReg, MEM_Result, WriteData, Zero, MEM_Destination;
int WB_RegWrite, WB_MemtoReg, WB_Result, ReadData, WB_Destination;
static int Memory[32] = { 0 };
static int Register[32] = { 0 };
static int line = 0;
string instruction;
char Cyc[5][4];
int cycle = 1;
static int stall_count = 0;
bool IF_over = false, ID_over = false, EX_over = false, MEM_over = false, WB_over = false;
bool beq_comfirm = false;
void IF() {
     //next_line 是用來確定這一次讀取有指令,才會讓PC+4,否則維持原PC
     bool next_line = false;
     //stall判定,並且令stall期間的程式不會結束
     string temp = instruction;

     fstream input;
     input.open("memory.txt");
     for (int i = 0; i <= line; i++) {
          if (getline(input, instruction)) {
               if (i == line) {
                    next_line = true;
                    for (int i = 0; i < 3; i++)
                    {
                         Cyc[0][i] = instruction[i];
                    }
                    Cyc[0][3] = '\0';
                    fstream out;
                    out.open("result.txt", ios::out | ios::app);
                    out << "	" << Cyc[0] << ":IF" << endl;
                    out.close();
                    if (stall_count > 0) {
                         ID_over = false;
                         IF_over = false;
                         instruction = temp;
                         return;
                    }
                    for (int i = 0; i < 4; i++) {
                         Cyc[1][i] = Cyc[0][i];
                         Cyc[0][i] = '0';
                    }
               }
          }
     }
     if (next_line == true)line++;
     input.close();
     //IF做事結束,ID該做事
     IF_over = true; ID_over = false;
}

void ID() {
     //stall判定,並且令stall期間的程式不會結束
     if (stall_count > 0) {
          ID_over = false;
          if (Cyc[1][0] != '0')//stall 期間的輸出
          {
               fstream out;
               out.open("result.txt", ios::out | ios::app);
               out << "	" << Cyc[1] << ":ID" << endl;
               out.close();
          }
          return;
     }
     int format = 0;
     int space[3];
     int work = 0;
     int temp_rs, temp_rt, temp_rd;
     for (int i = 0; i < instruction.length(); i++) {
          if (instruction[i] == ' ') {
               space[format] = i;
               format++;
          }
     }
     //運用指令中空白數量區分 R-format 與 I-format ,但在本程式中將 branch 特別歸類為 R-format 以便區隔
     if (format == 2) {//I-format
          if (instruction[0] == 'l') {//lw
               EX_RegDst = 0; EX_ALUSrc = 1;
               EX_Branch = 0; EX_MemRead = 1, EX_MemWrite = 0;
               EX_RegWrite = 1; EX_MemtoReg = 1;
               work = 1;
               //find rd 為了避免溝通上的不便,將要寫回暫存器的統稱rd,RegDst等同不用
               if (instruction[space[0] + 3] >= 48 && instruction[space[0] + 3] <= 57) {
                    rd = ((int)instruction[space[0] + 3] - 48) + ((int)instruction[space[0] + 2] - 48) * 10;
               }
               else if (instruction[space[0] + 2] >= 48 && instruction[space[0] + 2] <= 57) {
                    rd = ((int)instruction[space[0] + 2] - 48);
               }
          }
          else if (instruction[0] == 's') {//sw 
               EX_RegDst = 2; EX_ALUSrc = 1;
               EX_Branch = 0; EX_MemRead = 0; EX_MemWrite = 1;
               EX_RegWrite = 0; EX_MemtoReg = 2;
               work = 2;
               //find rt
               if (instruction[space[0] + 3] >= 48 && instruction[space[0] + 3] <= 57) {
                    temp_rt = ((int)instruction[space[0] + 3] - 48) + ((int)instruction[space[0] + 2] - 48) * 10;
                    rt = Register[temp_rt];
               }
               else if (instruction[space[0] + 2] >= 48 && instruction[space[0] + 2] <= 57) {
                    temp_rt = ((int)instruction[space[0] + 2] - 48);
                    rt = Register[temp_rt];
               }
          }
          //find rs && sign-extend  本處寫死 sign-extend 最多只有2位數
          if (space[1] + 1 == '-') {//有負號的
               if (instruction[space[1] + 3] >= 48 && instruction[space[1] + 3] <= 57) {
                    sign_extend = -(((int)instruction[space[1] + 3] - 48) + ((int)instruction[space[1] + 2] - 48) * 10) / 4;
                    if (instruction[space[1] + 6] >= 48 && instruction[space[1] + 6] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 6] - 48) + ((int)instruction[space[1] + 5] - 48) * 10;
                         rs = Register[temp_rs];
                    }
                    else if (instruction[space[1] + 5] >= 48 && instruction[space[1] + 5] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 5] - 48);
                         rs = Register[temp_rs];
                    }
               }
               else if (instruction[space[1] + 2] >= 48 && instruction[space[1] + 2] <= 57) {
                    sign_extend = -(((int)instruction[space[1] + 2] - 48)) / 4;
                    if (instruction[space[1] + 5] >= 48 && instruction[space[1] + 5] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 5] - 48) + ((int)instruction[space[1] + 4] - 48) * 10;
                         rs = Register[temp_rs];
                    }
                    else if (instruction[space[1] + 4] >= 48 && instruction[space[1] + 4] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 4] - 48);
                         rs = Register[temp_rs];
                    }
               }
          }
          else {//沒負號的
               if (instruction[space[1] + 2] >= 48 && instruction[space[1] + 2] <= 57) {
                    sign_extend = (((int)instruction[space[1] + 2] - 48) + ((int)instruction[space[1] + 1] - 48) * 10) / 4;
                    if (instruction[space[1] + 6] >= 48 && instruction[space[1] + 6] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 6] - 48) + ((int)instruction[space[1] + 5] - 48) * 10;
                         rs = Register[temp_rs];
                    }
                    else if (instruction[space[1] + 5] >= 48 && instruction[space[1] + 5] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 5] - 48);
                         rs = Register[temp_rs];
                    }
               }
               else if (instruction[space[1] + 1] >= 48 && instruction[space[1] + 1] <= 57) {
                    sign_extend = (((int)instruction[space[1] + 1] - 48)) / 4;
                    if (instruction[space[1] + 5] >= 48 && instruction[space[1] + 5] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 5] - 48) + ((int)instruction[space[1] + 4] - 48) * 10;
                         rs = Register[temp_rs];
                    }
                    else if (instruction[space[1] + 4] >= 48 && instruction[space[1] + 4] <= 57) {
                         temp_rs = ((int)instruction[space[1] + 4] - 48);
                         rs = Register[temp_rs];
                    }
               }
          }
     }
     else if (format == 3) {//R-format
          if (instruction[0] == 'a') {
               EX_RegDst = 1; EX_ALUSrc = 0;
               EX_Branch = 0; EX_MemRead = 0, EX_MemWrite = 0;
               EX_RegWrite = 1; EX_MemtoReg = 0;
               work = 3;
          }
          else if (instruction[0] == 's') {
               EX_RegDst = 1; EX_ALUSrc = 0;
               EX_Branch = 0; EX_MemRead = 0; EX_MemWrite = 0;
               EX_RegWrite = 1; EX_MemtoReg = 0;
               work = 3;
          }
          else if (instruction[0] == 'b') {
               EX_RegDst = 2; EX_ALUSrc = 0;
               EX_Branch = 1; EX_MemRead = 0; EX_MemWrite = 0;
               EX_RegWrite = 0; EX_MemtoReg = 2;
               work = 4;
          }
          if (work == 3) {
               //find rd 
               if (instruction[space[0] + 3] >= 48 && instruction[space[0] + 3] <= 57) {
                    rd = ((int)instruction[space[0] + 3] - 48) + ((int)instruction[space[0] + 2] - 48) * 10;
               }
               else if (instruction[space[0] + 2] >= 48 && instruction[space[0] + 2] <= 57) {
                    rd = ((int)instruction[space[0] + 2] - 48);
               }
               //find rs
               if (instruction[space[1] + 3] >= 48 && instruction[space[1] + 3] <= 57) {
                    temp_rs = ((int)instruction[space[1] + 3] - 48) + ((int)instruction[space[1] + 2] - 48) * 10;
                    rs = Register[temp_rs];
               }
               else if (instruction[space[1] + 2] >= 48 && instruction[space[1] + 2] <= 57) {
                    temp_rs = ((int)instruction[space[1] + 2] - 48);
                    rs = Register[temp_rs];
               }
               //find rt 分為正負 add 取正  sub 取負
               if (instruction[0] == 'a') {
                    if (instruction[space[2] + 1] == '$') {
                         if (instruction[space[2] + 3] >= 48 && instruction[space[2] + 3] <= 57) {
                              temp_rt = ((int)instruction[space[2] + 3] - 48) + ((int)instruction[space[2] + 2] - 48) * 10;
                              rt = Register[temp_rt];
                         }
                         else if (instruction[space[2] + 2] >= 48 && instruction[space[2] + 2] <= 57) {
                              temp_rt = ((int)instruction[space[2] + 2] - 48);
                              rt = Register[temp_rt];
                         }
                    }
                    else {//find sign-extend 本處寫死 sign-extend 最多只有2位數
                         int temp = 1;
                         rt = 0;
                         if (space[2] + 1 == '-') {
                              for (int i = instruction.length() - 1; i > space[2] + 1; i--) {
                                   sign_extend += ((int)instruction[i] - 48)*temp;
                              }
                              sign_extend = -sign_extend;
                         }
                         else {
                              for (int i = instruction.length() - 1; i > space[2]; i--) {
                                   sign_extend += ((int)instruction[i] - 48)*temp;
                              }
                         }
                    }
               }
               else if (instruction[0] == 's') {
                    if (instruction[space[2] + 1] == '$') {
                         if (instruction[space[2] + 3] >= 48 && instruction[space[2] + 3] <= 57) {
                              temp_rt = ((int)instruction[space[2] + 3] - 48) + ((int)instruction[space[2] + 2] - 48) * 10;
                              rt = -Register[temp_rt];
                         }
                         else if (instruction[space[2] + 2] >= 48 && instruction[space[2] + 2] <= 57) {
                              temp_rt = ((int)instruction[space[2] + 2] - 48);
                              rt = -Register[temp_rt];
                         }
                    }
                    else {//find sign-extend 本處寫死 sign-extend 最多只有2位數
                         int temp = 1;
                         rt = 0;
                         if (space[2] + 1 == '-') {
                              for (int i = instruction.length() - 1; i > space[2] + 1; i--) {
                                   sign_extend += ((int)instruction[i] - 48)*temp;
                              }
                         }
                         else {
                              for (int i = instruction.length() - 1; i > space[2]; i--) {
                                   sign_extend += ((int)instruction[i] - 48)*temp;
                              }
                              sign_extend = -sign_extend;
                         }
                    }
               }
          }
          else if (work == 4) {
               //find rs 
               if (instruction[space[0] + 3] >= 48 && instruction[space[0] + 3] <= 57) {
                    temp_rs = ((int)instruction[space[0] + 3] - 48) + ((int)instruction[space[0] + 2] - 48) * 10;
                    rs = Register[temp_rs];
               }
               else if (instruction[space[0] + 2] >= 48 && instruction[space[0] + 2] <= 57) {
                    temp_rs = ((int)instruction[space[0] + 2] - 48);
                    rs = Register[temp_rs];
               }
               //find rt
               if (instruction[space[1] + 3] >= 48 && instruction[space[1] + 3] <= 57) {
                    temp_rt = ((int)instruction[space[1] + 3] - 48) + ((int)instruction[space[1] + 2] - 48) * 10;
                    rt = -Register[temp_rt];
               }
               else if (instruction[space[1] + 2] >= 48 && instruction[space[1] + 2] <= 57) {
                    temp_rt = ((int)instruction[space[1] + 2] - 48);
                    rt = -Register[temp_rt];
               }
               //find sign-extend 本處寫死 sign-extend 最多只有2位數
               int temp = 1;
               sign_extend = 0;
               if (instruction[space[2] + 1] == '-') {
                    for (int i = instruction.length() - 1; i > space[2] + 1; i--) {
                         sign_extend += ((int)instruction[i] - 48)*temp;
                    }
                    sign_extend = -sign_extend;
               }
               else {
                    for (int i = instruction.length() - 1; i > space[2]; i--) {
                         sign_extend += ((int)instruction[i] - 48)*temp;
                    }
               }
          }
     }
     enum work_con { lw = 1, sw, r_format, beq };


     if (work == lw) {//lw stall
          temp_rs = rs + sign_extend;
          if (MEM_Destination == temp_rs && MEM_RegWrite == 1) {
               stall_count = 2;
               EX_RegDst = 0; EX_ALUSrc = 0;
               EX_Branch = 0; EX_MemRead = 0, EX_MemWrite = 0;
               EX_RegWrite = 0; EX_MemtoReg = 0;
          }
     }
     else if (work == sw) {//sw stall
          if (MEM_Destination == temp_rt && MEM_RegWrite == 1) {
               stall_count = 2;
               EX_RegDst = 0; EX_ALUSrc = 0;
               EX_Branch = 0; EX_MemRead = 0, EX_MemWrite = 0;
               EX_RegWrite = 0; EX_MemtoReg = 0;
          }
     }
     else if (work == r_format) {//r-format stall
          if ((MEM_Destination == temp_rs || MEM_Destination == temp_rt) && MEM_RegWrite == 1) {
               stall_count = 2;
               EX_RegDst = 0; EX_ALUSrc = 0;
               EX_Branch = 0; EX_MemRead = 0, EX_MemWrite = 0;
               EX_RegWrite = 0; EX_MemtoReg = 0;
          }
     }
     else if (work == beq) {//work stall
          if ((MEM_Destination == temp_rs || MEM_Destination == temp_rt) && MEM_RegWrite == 1) {
               stall_count = 2;
               EX_RegDst = 0; EX_ALUSrc = 0;
               EX_Branch = 0; EX_MemRead = 0, EX_MemWrite = 0;
               EX_RegWrite = 0; EX_MemtoReg = 0;
          }
          else {
               stall_count = 1;
               instruction = "";
               /*EX_RegDst = 0; EX_ALUSrc = 0;
               EX_Branch = 0; EX_MemRead = 0, EX_MemWrite = 0;
               EX_RegWrite = 0; EX_MemtoReg = 0;*/
          }
     }
     //輸出-----------
     if (beq_comfirm) {//如果beq判定要跳轉 則先前IF指令部分不傳入ID
          Cyc[1][0] = '0';
          beq_comfirm = false;
     }
     if (Cyc[1][0] != '0')
     {
          fstream out;
          out.open("result.txt", ios::out | ios::app);
          out << "	" << Cyc[1] << ":ID" << endl;
          out.close();
     }
     if (stall_count < 2) {
          for (int i = 0; i < 4; i++)
          {
               Cyc[2][i] = Cyc[1][i];
               Cyc[1][i] = '0';
          }
     }
     //---------------
     //over
     ID_over = true; EX_over = false;
}

void EX() {
     //輸出------------------
     if (Cyc[2][0] != '0')
     {
          fstream out;
          out.open("result.txt", ios::out | ios::app);
          out << "	" << Cyc[2] << ":EX ";
          if (EX_RegDst == 2) { out << 'X'; }
          else { out << EX_RegDst; }
          out << EX_ALUSrc << " " << EX_Branch << EX_MemRead << EX_MemWrite << " " << EX_RegWrite;
          if (EX_MemtoReg == 2) { out << 'X' << endl; }
          else { out << EX_MemtoReg << endl; }

          for (int i = 0; i < 4; i++)
          {
               Cyc[3][i] = Cyc[2][i];
               Cyc[2][i] = '0';
          }
          out.close();
     }
     //--------------------
     //EX_ALUSrc:0代表R-format 1代表I-format
     if (EX_ALUSrc == 0)
     {
          MEM_Result = rt + rs;//MEM_Result就是rd，直接把結果丟到MEM階段
     }
     else //EX_ALUSrc == 1
     {
          MEM_Result = rs + sign_extend;
     }
     if (MEM_Result == 0)
     {
          Zero = 1;//MEM階段
     }

     //FOR BRANCH:在EX階段就判斷下一個IF是否要BRANCH(PPT86頁是錯的)
     if (EX_Branch == 1 && Zero == 1)//要BRANCH
     {
          line = line + sign_extend;//在這裡直接計算BRANCH的下一個指令要讀第幾行，就不用再IF透過PCsrc做選擇
                                    //因為Branch判斷完會有一個cycle的EX stall,避免再次執行Branch,所以清空Control Signal

          beq_comfirm = true;//輸出所需
     }

     //EX_RegDst:0代表rt 1代表rd
     //這邊統一都使用rd
     //if(EX_RegDst == 0)
     //{
     //	MEM_Destination = rt;
     //}
     //else //EX_RegDst == 1
     //{
     MEM_Destination = rd;
     //}

     //設定MEM階段的WriteData
     WriteData = rt;
     //傳EX階段沒有用到的bit到MEM階段
     MEM_Branch = EX_Branch;
     MEM_RegWrite = EX_RegWrite;
     MEM_MemRead = EX_MemRead;
     MEM_MemWrite = EX_MemWrite;
     MEM_MemtoReg = EX_MemtoReg;
     //clean all signal in EXE
     EX_RegDst = 0; EX_ALUSrc = 0;
     EX_Branch = 0; EX_MemRead = 0, EX_MemWrite = 0;
     EX_RegWrite = 0; EX_MemtoReg = 0;
     Zero = 0;
     //over
     EX_over = true; MEM_over = false;
}

void MEM() {
     //輸出--------------
     if (Cyc[3][0] != '0')
     {
          fstream out;
          out.open("result.txt", ios::out | ios::app);
          out << "	" << Cyc[3] << ":MEM ";
          out << MEM_Branch << MEM_MemRead << MEM_MemWrite << " " << MEM_RegWrite;
          if (MEM_MemtoReg == 2) { out << 'X' << endl; }
          else { out << MEM_MemtoReg << endl; }

          for (int i = 0; i < 4; i++)
          {
               Cyc[4][i] = Cyc[3][i];
               Cyc[3][i] = '0';
          }
          out.close();
     }
     //-----------------
     //MEM_MemRead
     if (MEM_MemRead == 1)//將第[MEM_Result]個記憶體內容放到ReadData
     {
          ReadData = Memory[MEM_Result];
     }
     else//MEM_MemRead = 0，什麼都不做
     {
     }
     //MEM_MemWrite
     if (MEM_MemWrite == 1)//將第[WriteData]個暫存器寫入第[MEM_Result]個記憶體
     {
          Memory[MEM_Result] = WriteData;
     }
     else//MEM_MemWrite = 0，什麼都不做
     {
     }

     //傳MEM階段沒有用到的bit到WB階段
     WB_RegWrite = MEM_RegWrite;
     WB_Destination = MEM_Destination;//PPT86頁下面(RegDst)那條線
     WB_MemtoReg = MEM_MemtoReg;
     WB_Result = MEM_Result;//PPT86頁(MemRead)那條線
     //clean all signal in MEM
     MEM_Branch = 0; MEM_MemRead = 0, MEM_MemWrite = 0;
     MEM_RegWrite = 0; MEM_MemtoReg = 0;
     //over
     MEM_over = true; WB_over = false;
}

void WB() {
     //輸出----------
     if (Cyc[4][0] != '0')
     {
          fstream out;
          out.open("result.txt", ios::out | ios::app);
          out << "	" << Cyc[4] << ":WB ";
          out << WB_RegWrite;
          if (WB_MemtoReg == 2) { out << 'X' << endl; }
          else { out << WB_MemtoReg << endl; }

          for (int i = 0; i < 4; i++)
          {
               Cyc[4][i] = '0';
          }
          out.close();
     }
     //-------------
     //這裡只做一件事情:根據RegWrite決定要不要把資料寫回Reg
     //WB_RegWrite
     if (WB_RegWrite == 1)//寫入
     {
          if (WB_MemtoReg == 1)//寫入ReadData
          {
               Register[WB_Destination] = ReadData;
          }
          else//寫入WB_Result
          {
               Register[WB_Destination] = WB_Result;
          }
     }
     else//不要寫入
     {
     }
     //clean all signal in WB
     WB_RegWrite = 0; WB_MemtoReg = 0;
     //over
     WB_over = true;
}

void init_value()
{
     //設置32個暫存器的值都是1
     for (int i = 0; i < 32; ++i)
     {
          Memory[i] = 1;
          Register[i] = 1;
     }
     Register[0] = 0;
     //IF
     IF_PCSrc = 0;
     //EX
     EX_ALUOP0 = 0, EX_ALUOP1 = 0, EX_RegDst = 0, EX_Branch = 0, EX_RegWrite = 0,
          EX_ALUSrc = 0, EX_MemRead = 0, EX_MemWrite = 0, EX_MemtoReg = 0, rs = 0, rt = 0, rd = 0, sign_extend = 0;
     //MEM
     MEM_Branch = 0, MEM_RegWrite = 0, MEM_MemRead = 0, MEM_MemWrite = 0,
          MEM_MemtoReg = 0, MEM_Result = 0, WriteData = 0, Zero = 0, MEM_Destination = 0;
     //WB
     WB_RegWrite = 0, WB_MemtoReg = 0, WB_Result = 0, ReadData = 0, WB_Destination = 0;
     //輸出存指令歸零
     for (int i = 0; i < 5; i++)
     {
          for (int j = 0; j < 3; j++)
          {
               Cyc[i][j] = '0';
          }
     }
}
int main() {
     static int max_line;
     init_value();
     //while執行一輪是一個cycle
     int temp = 0;
     fstream out;
     out.open("result.txt", ios::out);
     out.close();
     fstream get_max_line;
     get_max_line.open("memory.txt");
     while (getline(get_max_line, instruction)) {
          temp++;
     }
     instruction = "";
     get_max_line.close();
     max_line = temp;
     while (true)
     {
          fstream out;
          out.open("result.txt",ios::out|ios::app);
          out << "Cycle " << cycle << endl;
          out.close();
          if (!WB_over) {
               WB();
          }
          if (!MEM_over) {
               MEM();
          }
          if (!EX_over) {
               EX();
          }
          if (!ID_over || stall_count>0) {
               ID();
          }
          if (line == max_line) {

               IF_over = true;
          }
          else {
               IF();
          }
                    
          stall_count--;
          if (IF_over && ID_over && EX_over && MEM_over && WB_over) { break; }
          cycle++;
     }

     //fstream out;
     out.open("result.txt", ios::out | ios::app);
     out << "需要花 " << cycle << " 個cycles" << endl;
     for (int i = 0; i < 32; i++) {
          out << "$" << i << " ";
     }
     out << endl;
     for (int i = 0; i < 32; i++) {
          out << " " << Register[i] << " ";
          if (i > 10) { out << " "; }
     }
     out << endl;
     for (int i = 0; i < 32; i++) {
          out << "W" << i << "  ";
     }
     out << endl;
     for (int i = 0; i < 32; i++) {
          out << " " << Memory[i] << "  ";
          if (i > 10) { out << " "; }
     }
     out << endl;
     out.close();


     system("PAUSE");
     return 0;
}