using namespace std;

void cut(int n, int sx, int sy, int x, int y){
    int mx = sx+n/2-1, my = sy+n/2-1;
    if(x > mx && y > my){
        Report(mx,my,mx+1,my,mx,my+1);
        if(n<=2)
            return;
        cut(n/2,sx,sy,mx,my);
        cut(n/2,mx+1,sy,mx+1,my);
        cut(n/2,sx,my+1,mx,my+1);
        cut(n/2,mx+1,my+1,x,y);
    }else if(x > mx && y <= my){
        Report(mx,my,mx,my+1,mx+1,my+1);
        if(n<=2)
            return;
        cut(n/2,sx,sy,mx,my);
        cut(n/2,sx,my+1,mx,my+1);
        cut(n/2,mx+1,sy,x,y);
        cut(n/2,mx+1,my+1,mx+1,my+1);
    }else if(x <= mx && y > my){
        Report(mx,my,mx+1,my,mx+1,my+1);
        if(n<=2)
            return;
        cut(n/2,sx,sy,mx,my);
        cut(n/2,mx+1,sy,mx+1,my);
        cut(n/2,sx,my+1,x,y);
        cut(n/2,mx+1,my+1,mx+1,my+1);
    }else if(x <= mx && y <= my){
        Report(mx+1,my+1,mx+1,my,mx,my+1);
        if(n<=2)
            return;
        cut(n/2,sx,sy,x,y);
        cut(n/2,mx+1,sy,mx+1,my);
        cut(n/2,sx,my+1,mx,my+1);
        cut(n/2,mx+1,my+1,mx+1,my+1);
    }
}
void solve(int n, int x, int y){
    cut(n,1,1,x,y);
}