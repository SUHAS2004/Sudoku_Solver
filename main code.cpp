#include <iostream>
using namespace std;
int input(int table[9][9]){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin>>table[i][j];
        }
    }
        
 return table[9][9];
}
void table_display(int table[9][9]){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout<<table[i][j];
            if(j==2||j==5){
                cout<<"|";
            }
        }
        cout<<endl;
        if (i==2||i==5){
            cout<<"-----------"<<endl;
        }
    } 
}
bool row_check(int table[9][9],int n,int i,int j){
    bool res;
    for(int j1=0;j1<9;++j1){        
        if(table[i][j1]==n){
            res = false;
            break;
        }
        else{
            res = true;
        }
    }   
    return res;
}
bool colmn_check(int table[9][9],int n,int i,int j){
    bool res;
    for(int i1=0;i1<9;++i1) {
        if(table[i1][j]==n){
            res = false;
            break;
        }
        else{
            res = true;
        }
    }   

    return res;
}
int box_finder(int i,int j){
    int num_pos[2]={1,0};
    for(int a=0;a<9;a+=3){
        if(i>=a&&i<a+3){
            num_pos[0]=a;
        }
    }
    for(int b=0;b<9;b+=3){
        if(j>=b&&j<b+3){
            num_pos[1]=b;
        }    
        
    }
    return 10*num_pos[0]+num_pos[1];
}
bool box_check(int table[9][9],int n,int i,int j){
    int box_pos0=box_finder(i,j)/10;
    int box_pos1=box_finder(i,j)-box_pos0*10;
    bool res;
    for(int i=box_pos0;i<box_pos0+3;++i){
        for(int j=box_pos1;j<box_pos1+3;++j){
            if(table[i][j]==n){
                res = false;
                break;
            }
            else{
                res = true;
            }            
        }
        if(res==false){
            break;
        }
    }
    return res;
}
bool fnl_ck(int table[9][9],int n,int i,int j){
    bool res;
    if(row_check(table,n,i,j)==true&&colmn_check(table,n,i,j)==true&&box_check(table,n,i,j)==true){
        res = true;    
    }
    else{
        res = false;
    }
    return res;
}
bool finished(int table[9][9]){
    bool res=true;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(table[i][j]==0){
                res=false;
            }  
        }
    }
    return res;
}
int fill(int table[9][9],int i,int j){
    int count=0;
    if(table[i][j]==0){
        for(int n=1;n<=9;n++){
            if(fnl_ck(table,n,i,j)==true){
                count++;
            }
        }
        if(count==1){
            for(int n=1;n<=9;n++){
                if(fnl_ck(table,n,i,j)==true){
                    table[i][j]=n;
                }
            }
        }
    }
    return table[9][9];
}
int main() {
    
    int table[9][9];
    input(table);
    table_display(table);
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            int n = table[i][j];
            fill(table,i,j);
            if(table[i][j]!=n){
                i=0;
                j=0;
            if(finished(table)==true){
                i=10;
                j=10;
            }
            }
        }
    }
    fill(table,0,0);
    cout<<"\n";
    cout<<"\n";
    table_display(table);
    return 0;
}
