/*Bomberman lives in a rectangular grid. Each cell in the grid either contains a bomb or nothing at all.

Each bomb can be planted in any cell of the grid but once planted, it will detonate after exactly 3 seconds. Once a bomb detonates, it’s destroyed — along with anything in its four neighboring cells. This means that if a bomb detonates in cell i,j, any valid cells (i+1,j)and (i,j+1) are cleared. If there is a bomb in a neighboring cell, the neighboring bomb is destroyed without detonating, so there’s no chain reaction.

Bomberman is immune to bombs, so he can move freely throughout the grid. Here’s what he does:
Initially, Bomberman arbitrarily plants bombs in some of the cells, the initial state.
After one second, Bomberman does nothing.
After one more second, Bomberman plants bombs in all cells without bombs, thus filling the whole grid with bombs. No bombs detonate at this point.
After one more second, any bombs planted exactly three seconds ago will detonate. Here, Bomberman stands back and observes.
Bomberman then repeats steps 3 and 4 indefinitely.
Note that during every second Bomberman plants bombs, the bombs are planted simultaneously (i.e., at the exact same moment), and any bombs planted at the same time will detonate at the same time.

Given the initial configuration of the grid with the locations of Bomberman’s first batch of planted bombs, determine the state of the grid after N seconds.

For example, if the initial grid looks like:

...
.O.
...
it looks the same after the first second. After the second second, Bomberman has placed all his charges:

OOO
OOO
OOO
At the third second, the bomb in the middle blows up, emptying all surrounding cells:

...
...
...
Function Description

Complete the bomberMan function in the editory below. It should return an array of strings that represent the grid in its final state.

bomberMan has the following parameter(s):

n: an integer, the number of seconds to simulate
grid: an array of strings that represents the grid

Input Format

The first line contains three space-separated integers r, c, and n, The number of rows, columns and seconds to simulate.
Each of the next r lines contains a row of the matrix as a single string of c characters. The . character denotes an empty cell, and the O character (ascii 79) denotes a bomb.

Output Format

Print the grid’s final state. This means R lines where each line contains C characters, and each character is either a . or an O (ascii 79). This grid must represent the state of the grid after n seconds.

Sample Input

6 7 3
.......
...O...
....O..
.......
OO.....
OO.....
Sample Output

OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO
Explanation

The initial state of the grid is:

.......
...O...
....O..
.......
OO.....
OO.....
Bomberman spends the first second doing nothing, so this is the state after 1 second:

.......
...O...
....O..
.......
OO.....
OO.....
Bomberman plants bombs in all the empty cells during his second second, so this is the state after 2 seconds:

OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
In his third second, Bomberman sits back and watches all the bombs he planted 3 seconds ago detonate. This is the final state after  seconds:

OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<string> bomberMan(int n, vector<string> grid) {
    
    vector <string> arr1; 
    string s ="";
    int r=grid.size();
    int m=grid[r-1].size();
    if(n==1)
    return grid;
    
    
    for(int i=0;i<r;i++)
    {   s="";
        for(int i=0;i<m;i++)
        {
         s+="O";
         }
         arr1.push_back(s);

    }
    if(n%2==0)
    return arr1;
    string arr[r][m];
    string arr2[r][m];
    string arr3[r][m];
    arr1.clear();
    cout<<endl;

// 6 7 3   
// .......     
// ...O...    
// ....O..
// .......
// OO.....
// OO.....
  


  
    
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[i][j]=grid[i][j];
            arr2[i][j]=grid[i][j];
            arr3[i][j]=grid[i][j];
         
            
        } 
       
    }
    
    if((n-1)%4!=0)
    n=3;
    else
    n=5;
    
  
 
 
 for(int k=2;k<=n;k++)
 {
     
    
    if(k%2==0)
    {
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j]="O";
            }  
        }
        
      
        
        
     
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]!=arr2[i][j])
                {  
                    arr2[i][j]="O";
                }
                else
                arr2[i][j]=".";
                
            } 
        }

        
 
        
        
        
        
        
        
    }
    
    
     
    else 
    if(k%2!=0)
    {
      
        
        
        

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            { 

                if(arr3[i][j]=="O")
                {   
                    if(i!=r-1)
                    arr[i+1][j]=".";

                    if(i!=0)
                    arr[i-1][j]=".";

                    if(j!=0)
                    arr[i][j-1]=".";

                    if(j!=m-1)
                    arr[i][j+1]=".";

                    arr[i][j]=".";
                }
            }
           
        }
        
      


    



        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr3[i][j]=arr2[i][j];
            }  
        }
        
        
   
        
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {   if(arr3[i][j]==arr[i][j]&&arr[i][j]=="O")
                arr3[i][j]="O";
                else
                arr3[i][j]=".";
                
            }  
        }
        
        
        
        
        
       

        
        
        
        
    }
}

     
     
     string s2d="";
        for(int i=0;i<r;i++)
        {  s2d = "";
            for(int j=0;j<m;j++)
            {   
             s2d+=arr[i][j];
            } 
            arr1.push_back(s2d);
            cout<<endl; 

        }
     
     
   
     
     
     
     

 return arr1;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
