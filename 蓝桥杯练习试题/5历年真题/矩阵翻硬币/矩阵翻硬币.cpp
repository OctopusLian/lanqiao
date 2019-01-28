//#pragma comment(linker,"/STACK:102400000,102400000")
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#ifndef ONLINE_JUDGE
#include<ctime>
#endif
#define __________ ios_base::sync_with_stdio(0),cin.tie(0);
#define ll long long
#define IT(x) __typeof((x).begin())
#define FS(i,a) for(int i=0;a[i];i++)
#define FE(x,ctn) for(IT(ctn)x=(ctn).begin(),CluhxSchFuDeugk=(ctn).end();x!=CluhxSchFuDeugk;x++)
#define FR(i,en) for(int i=0,CBRfZzHVFp=(en);i<CBRfZzHVFp;i++)
#define FOR(i,en) for(int i=1,SbKCIcakJTeYVqs=(en);i<=SbKCIcakJTeYVqs;i++)
#define FFR(i,x,y) for(int i=(x),alVDbhLBoMEGSwA=(y);i<=alVDbhLBoMEGSwA;i++)
#define DFFR(i,x,y) for(int i=(x),NWYfecAcmGBMJuU=(y);i>=NWYfecAcmGBMJuU;i--)
#define mp make_pair
#define pb push_back
#define pq priority_queue
#define fi first
#define se second
#define sqr(x) (x)*(x)
#define all(x) (x).begin(),(x).end()
#define clr(x) memset((x),0,sizeof(x))
#define inf(x) memset((x),0x7F,sizeof(x))
#define _inf(x) memset((x),0x80,sizeof(x))
#define SI(x) ~scanf("%d",&(x))
#define SII(x,y) ~scanf("%d%d",&(x),&(y))
#define SIII(x,y,z) ~scanf("%d%d%d",&(x),&(y),&(z))
#define SD(x) ~scanf("%lf",&(x))
#define SDD(x,y) ~scanf("%lf%lf",&(x),&(y))
#define SDDD(x,y,z) ~scanf("%lf%lf%lf",&(x),&(y),&(z))
#define SS(x) ~scanf("%s",(x))
#define SSI(x,y) ~scanf("%s%d",(x),&(y))
#define SIS(y,x) ~scanf("%d%s",&(y),(x))
#define PI(x) printf("%d ",(x))
#define PD(x) printf("%f ",(x))
#define PS(x) printf("%s",(x))
#define PIN(x) printf("%d\n",(x))
#define PDN(x) printf("%f\n",(x))
#define NL puts("");
#define S64(x) ~scanf("%I64d",&(x))
#define SS6464(x,y) ~scanf("%I64d%I64d",&(x),&(y))
#define P64(x) printf("%I64d ",(x))
#define P64N(x) printf("%I64d\n",(x))

template<class T1,class T2,class T3>
bool IN(T1 x,T2 y,T3 z){
  return x<=y&&x>=z||x<=z&&x>=y;
}

int kase;
const double pi=4*atan(1);

using namespace std;
//}

const int numlen = 5050; // 位数

int max(int a, int b) { return a>b?a:b; }
struct bign {
    int len, s[numlen];
    bign() {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign(int num) { *this = num; }
    bign(const char *num) { *this = num; }
    bign operator = (const int num) {
        char s[numlen];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator = (const char *num) {
        len = strlen(num);
        while(len > 1 && num[0] == '0') num++, len--;
        for(int i = 0;i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }

    void deal() {
        while(len > 1 && !s[len-1]) len--;
    }

    bign operator + (const bign &a) const {
        bign ret;
        ret.len = 0;
        int top = max(len, a.len) , add = 0;
        for(int i = 0;add || i < top; i++) {
            int now = add;
            if(i < len) now += s[i];
            if(i < a.len)   now += a.s[i];
            ret.s[ret.len++] = now%10;
            add = now/10;
        }
        return ret;
    }
    bign operator - (const bign &a) const {
        bign ret;
        ret.len = 0;
        int cal = 0;
        for(int i = 0;i < len; i++) {
            int now = s[i] - cal;
            if(i < a.len)   now -= a.s[i];
            if(now >= 0)    cal = 0;
            else {
                cal = 1; now += 10;
            }
            ret.s[ret.len++] = now;
        }
        ret.deal();
        return ret;
    }
    bign operator * (const bign &a) const {
        bign ret;
        ret.len = len + a.len;
        for(int i = 0;i < len; i++) {
            for(int j = 0;j < a.len; j++)
                ret.s[i+j] += s[i]*a.s[j];
        }
        for(int i = 0;i < ret.len; i++) {
            ret.s[i+1] += ret.s[i]/10;
            ret.s[i] %= 10;
        }
        ret.deal();
        return ret;
    }

    //乘以小数，直接乘快点
    bign operator * (const int num) {
        bign ret;
        ret.len = 0;
        int bb = 0;
        for(int i = 0;i < len; i++) {
            int now = bb + s[i]*num;
            ret.s[ret.len++] = now%10;
            bb = now/10;
        }
        while(bb) {
            ret.s[ret.len++] = bb % 10;
            bb /= 10;
        }
        ret.deal();
        return ret;
    }

    bign operator / (const bign &a) const {
        bign ret, cur = 0;
        ret.len = len;
        for(int i = len-1;i >= 0; i--) {
            cur = cur*10;
            cur.s[0] = s[i];
            while(cur >= a) {
                cur -= a;
                ret.s[i]++;
            }
        }
        ret.deal();
        return ret;
    }

    bign operator % (const bign &a) const {
        bign b = *this / a;
        return *this - b*a;
    }

    bign operator += (const bign &a) { *this = *this + a; return *this; }
    bign operator -= (const bign &a) { *this = *this - a; return *this; }
    bign operator *= (const bign &a) { *this = *this * a; return *this; }
    bign operator /= (const bign &a) { *this = *this / a; return *this; }
    bign operator %= (const bign &a) { *this = *this % a; return *this; }

    bool operator < (const bign &a) const {
        if(len != a.len)    return len < a.len;
        for(int i = len-1;i >= 0; i--) if(s[i] != a.s[i])
            return s[i] < a.s[i];
        return false;
    }
    bool operator > (const bign &a) const  { return a < *this; }
    bool operator <= (const bign &a) const { return !(*this > a); }
    bool operator >= (const bign &a) const { return !(*this < a); }
    bool operator == (const bign &a) const { return !(*this > a || *this < a); }
    bool operator != (const bign &a) const { return *this > a || *this < a; }

    string str() const {
        string ret = "";
        for(int i = 0;i < len; i++) ret = char(s[i] + '0') + ret;
        return ret;
    }
};
istream& operator >> (istream &in, bign &x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream &out, const bign &x) {
    out << x.str();
    return out;
}

bign Sqrt(bign x) {
    int a[numlen/2];
    int top = 0;
    for(int i = 0;i < x.len; i += 2) {
        if(i == x.len-1) {
            a[top++] = x.s[i];
        }
        else
            a[top++] = x.s[i] + x.s[i+1]*10;
    }
    bign ret = (int)sqrt((double)a[top-1]);
    int xx = (int)sqrt((double)a[top-1]);
    bign pre = a[top-1] - xx*xx;
    bign cc;
    for(int i = top-2;i >= 0; i--) {
        pre = pre*100 + a[i];
        cc = ret*20;
        for(int j = 9;j >= 0; j--) {
            bign now = (cc + j)*j;
            if(now <= pre) {
                ret = ret*10 + j;
                pre -= now;
                break;
            }
        }
    }
    return ret;
}

char a[1005],b[1005];

int main(){
  //__________;
  scanf("%s%s",a,b);
  bign x(a),y(b);
  x=Sqrt(x);
  y=Sqrt(y);
//  puts(x.str().c_str());
//  puts(y.str().c_str());
  puts((x*y).str().c_str());
}

/**
  #ifndef ONLINE_JUDGE
    ;
  #endif
**/
