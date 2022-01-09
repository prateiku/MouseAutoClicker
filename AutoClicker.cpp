#include<iostream>
#include<windows.h>



//Declare/init variables below
struct var{
    int indexv;
    int num=0;
    int c=0;
    int time;
    int k=0;
    int instance = 0;
    bool condition;
    bool conditionII = TRUE;
}v;
int rxinput[100];
int ryinput[100];
int lxinput[100];
int lyinput[100];
//Function
int keypressed(int key){
    return(GetAsyncKeyState(key) & 0x8000 != 0);
}

void CursorPosi(){
    v.indexv = 0;
    v.condition = TRUE;
    POINT cursor;
    while(v.condition){
        if(keypressed(VK_LBUTTON)||keypressed(VK_MBUTTON)){
            GetCursorPos(&cursor);
            lxinput[v.indexv] = cursor.x;
            lyinput[v.indexv] = cursor.y;
            rxinput[v.indexv] =  ryinput[v.indexv] = -1;          
            std::cout<<"Click:"<<++v.k<<std::endl;
            std::cout<<"Mouse X = "<<lxinput[v.indexv]<<std::endl;
            std::cout<<"Mouse Y = "<<lyinput[v.indexv]<<std::endl;
            ++v.indexv;
            ++v.instance;
        }
        else if(keypressed(VK_RBUTTON)){
            GetCursorPos(&cursor);
            lxinput[v.indexv] = lyinput[v.indexv] = -1;          
            rxinput[v.indexv] = cursor.x;
            ryinput[v.indexv] = cursor.y;
            std::cout<<"Click:"<<++v.k<<std::endl;
            std::cout<<"Mouse X = "<<rxinput[v.indexv]<<std::endl;
            std::cout<<"Mouse Y = "<<ryinput[v.indexv]<<std::endl;
            ++v.indexv;
            ++v.instance;
        }
        else if(keypressed(VK_NUMPAD2)){
            std::cout<<"Cursor recording stopped!"<<std::endl;
            v.condition = FALSE;
        }
    }
}
void RightClick(int a[], int b[])
{
    //POINT mouseCoords;
    //GetCursorPos(&mouseCoords);
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dwExtraInfo = 0;
    input.mi.mouseData = 0;
    input.mi.dx =a[v.c]*(65535.0f/ GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy =b[v.c]*(65535.0f/ GetSystemMetrics(SM_CYSCREEN));
    input.mi.time = 0;
    ++v.c;
    std::cout<<input.mi.dx<<input.mi.dy<<std::endl;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));

}

void LeftClick(int d[], int e[])
{
    //POINT mouseCoords;
    //GetCursorPos(&mouseCoords);
    
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dwExtraInfo = 0;
    input.mi.mouseData = 0;
    input.mi.dx =d[v.c]*(65535.0f/ GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy =e[v.c]*(65535.0f/ GetSystemMetrics(SM_CYSCREEN));
    input.mi.time = 0;
    ++v.c;
    std::cout<<input.mi.dx<<input.mi.dy<<std::endl;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));

}

void ClickCursor(int m[],int n[], int o[], int p[], int samay){
    std::cout<<"~ Simulating Clicks ~"<<std::endl;
    for(int i = 0;i<v.instance;++i){
        Sleep(samay);
        if(m[v.num] != -1){
            RightClick(lxinput,lyinput);
            std::cout<<"RIGHT:"<<v.num<<std::endl;
            }
        else if(o[v.num] != -1){
            LeftClick(rxinput,ryinput);
            std::cout<<"LEFT:"<<v.num<<std::endl;
        }
        ++v.num;
    }
    v.num = v.c = 0;   
}

/*void CursorRec(){
    while(v.condition){
        if(keypressed(VK_MBUTTON)){
            CursorPosi();
        }
        else if(keypressed(VK_F5)){
            v.condition=FALSE;
        }
    }
}*/
int main(){
    std::cout<<"===================HOTKEYS==================="<<std::endl;
    std::cout<<"| NUM1---------------Start recording clicks |"<<std::endl;
    std::cout<<"| NUM2----------------Stop recording clicks |"<<std::endl;
    std::cout<<"| NUM3--------------Display recorded clicks |"<<std::endl;
    std::cout<<"| NUM4--------------Start simulating clicks |"<<std::endl;
    std::cout<<"| NUM5----------------Exit the auto clicker |"<<std::endl;
    std::cout<<"| NUM6----------------Dispay hotkey menu    |"<<std::endl;
    std::cout<<"============================================="<<std::endl;
    do{
        if(keypressed(VK_NUMPAD6)){
            std::cout<<"===================HOTKEYS==================="<<std::endl;
            std::cout<<"| NUM1---------------Start recording clicks |"<<std::endl;
            std::cout<<"| NUM2----------------Stop recording clicks |"<<std::endl;
            std::cout<<"| NUM3--------------Display recorded clicks |"<<std::endl;
            std::cout<<"| NUM4--------------Start simulating clicks |"<<std::endl;
            std::cout<<"| NUM5----------------Exit the auto clicker |"<<std::endl;
	    std::cout<<"| NUM6----------------Dispay hotkey menu    |"<<std::endl;
            std::cout<<"============================================="<<std::endl;
        }
        if(keypressed(VK_NUMPAD1)){
            std::cout<<"~ cursor position is being recorded ~"<<std::endl;
            std::cout<<"Press NUM1 to record a click and pess NUM2 to terminate"<<std::endl;
            std::cout<<"\n"<<std::endl;
            CursorPosi();
        }
        if(keypressed(VK_NUMPAD3)){
            for(int j=0;j<v.indexv;++j){               
                std::cout<<"Left Click Cords:"<<lxinput[j]<<","<<lyinput[j]<<std::endl;
                std::cout<<"Right Click Cords:"<<rxinput[j]<<","<<ryinput[j]<<std::endl;
            }
            std::cout<<"Press NUM1 to record again or NUM4 to simulate recorded clicks."<<std::endl;
        }
        if(keypressed(VK_NUMPAD4)){
                //std::cout<<"press NUM4 to start simulating recorded clicks"<<std::endl;
                std::cout<<"Enter the interval beetween consecutive clicks in seconds:"<<std::endl;
                std::cin>>v.time;
                v.time = v.time*1000;
                while(TRUE){
                    if (!v.conditionII){
					break;
				    }
                    ClickCursor(lxinput,lyinput,rxinput,ryinput,v.time);
                    if (keypressed(VK_NUMPAD5)){
					    v.conditionII = false;
					    std::cout << "Stopped clicking" << std::endl;
				}                   
            }
        }
        if(keypressed(VK_NUMPAD5)){
            std::cout<<"EXITED";
        }
    }while(!keypressed(VK_NUMPAD5));
    return 0;    
}
