#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define FOR(n) for (ll f = 0; f < n; f++)
#define INF 1000000000000000000
 
//   Variables / declarations
ll t=0,n=0,m=0,k=0,a=0,b=0,c=0,d=0,i=0,j=0,x=-1,y=-2,z=-3,l=0,r=0;
ll cnt=0,sum=0,prod=1,maxx=0,minn=1000000007;
bool alter=false,check=false;
char sign='+';
string str;

bool dec_ord(const tuple<int,char,bool>& a, 
               const tuple<int,char,bool>& b)
{
    return (get<0>(a) > get<0>(b));
}
bool sortbysec(const tuple<int,char,bool>& a, 
               const tuple<int,char,bool>& b)
{
    return (get<1>(a) > get<1>(b));
}
bool sortby3rd(const tuple<int,char,bool>& a, 
               const tuple<int,char,bool>& b)
{
    return (get<2>(a) > get<2>(b));
    // (get<2>(a) ">" get<2>(b)) '>' for decreasing order! and '<' for increasing order!
}

bool compare(double a, double b)
{
    return ((int)a == (int)b);
} //lists ka .unique() function! 

void offline(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void fun(int& x,int y){(x<y)?x=y:1;}

int main(){
    offline();

    
    array<int,4> arr[2];

    //arr.fill(4); //only used for 1D arrays! can't use for multi - D arrays

    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            arr[i][j]=i+j;
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
        
    cout<<"\nover\n\n";

    tuple <int,char,float> run;
    tuple <int,char> run2(5,'y');
    run = make_tuple(2,'r',5.6);
    cout<<get<0>(run)<<' '<<get<1>(run)<<' '<<get<2>(run)<<"\n\n";

//tuple and deque/vector! and sorting by any value of tuple! either decreasing or increasing!
int inint;
char inchar;
bool inbool;
    deque <tuple<int,char,bool>> lol;
    for(i=0;i<3;i++){
        cin>>inint>>inchar>>inbool;
        lol.push_back(make_tuple(inint,inchar,inbool));
        get<0>(lol[i])++;
        get<1>(lol[i])++;
    }
sort(lol.begin(),lol.end(),dec_ord);
    FOR(3){
        cout<<get<0>(lol[f])<<' '<<get<1>(lol[f])<<' '<<get<2>(lol[f])<<'\n';
    }cout<<'\n';
lol[0].swap(lol[1]);//swap any two tuples! like this!
    FOR(3){
        cout<<get<0>(lol[f])<<' '<<get<1>(lol[f])<<' '<<get<2>(lol[f])<<'\n';
    }cout<<'\n';
sort(lol.begin(),lol.end(),sortbysec);
    FOR(3){
        cout<<get<0>(lol[f])<<' '<<get<1>(lol[f])<<' '<<get<2>(lol[f])<<'\n';
    }cout<<'\n';
sort(lol.begin(),lol.end(),sortby3rd);
    FOR(3){
        cout<<get<0>(lol[f])<<' '<<get<1>(lol[f])<<' '<<get<2>(lol[f])<<'\n';
    }cout<<'\n';
tuple <int,int,int> tied;
    a=12;b=234;c=125;
    tied = make_tuple(a,b,c);
    tie(c,a,b) = tied; 
        //its opposite to the make_tuple()! 
        //it assigns the values of tuple to the variables!
    cout<<a<<' '<<b<<' '<<c<<"\n\n";

auto combined = tuple_cat(lol[0],tied); //concatenate two tuples!
    cout<<get<0>(combined)<<' '<<get<1>(combined)<<' '<<get<2>(combined)<<' ';
    cout<<get<3>(combined)<<' '<<get<4>(combined)<<' '<<get<5>(combined)<<"\n\n";

/*
// Lists -- Double linked lists!!

    list <int> list1(2);// you can initialise like this! but cannot input the values like cin>>list1[i];
    	//because for lists! you cannot use the list[index] method to get the value!
    list <int> list2;
    list<int>::iterator it;int ind=0;
    for(ind=0;ind<3;ind++){cin>>a;list1.push_back(a);}
    for(i=0;i<3;i++){a=a+i*2;list2.push_front(a);}

    for(it=list1.begin();it!=list1.end();it++){cout<<(*it)<<' ';}cout<<'\n';
    for(it=list2.begin();it!=list2.end();it++){cout<<*it<<' ';}cout<<'\n';

    // can use pop_back() and pop_front
    // can use .front() and .back()
    cout<<list1.front()<<" "<<list2.back()<<"\n\n";

//swap two lists!
list1.swap(list2);

	for(it=list1.begin();it!=list1.end();it++){cout<<(*it)<<' ';}cout<<'\n';
    for(it=list2.begin();it!=list2.end();it++){cout<<*it<<' ';}cout<<'\n';

list <int> list3=list2;// '=' operator makes list3 = list2 //list3 = lsit2 = {x,y,z}
list <int> list4{182,21,41,9};
//concatenatte two lists! add a certain range of elements to another!
list1.splice(list1.begin(),list2); // puts all the list2 at the beginning of the list1
								  // nomore list2!!! now
for(auto x: list1){cout<<x<<' ';}cout<<"\n\n";
list4.splice(list4.end(),list3); //puts all the list3 at the first of list4!
								// nomore list3! list3 and 2 are empty now!
for(auto x: list4){cout<<x<<' ';}cout<<"\n\n";

	list2.splice(list2.begin(),list1,list1.begin());//adds first element of list1 to list2;
	for(auto x: list1){cout<<x<<' ';}cout<<"\n";
	for(auto x: list2){cout<<x<<' ';}cout<<"\n\n";

	it = list1.begin();// pointing towards the first element of list1!
	advance(it,1); // advances iterator once! points to the 2nd elem. of list1!
	
	list2.splice(list2.end(),list1,it);//adds 2nd or the elem. which iterator is pointing to of list1 to list2;
	for(auto x: list1){cout<<x<<' ';}cout<<"\n";
	for(auto x: list2){cout<<x<<' ';}cout<<"\n\n";

//using splice add a range of elem. from one list to another!
	it = list4.begin();
	advance(it,3);  //4th elem. of list4
	auto it2 = it; //4th
	advance(it,4);//4+4 / 8th elem. of list4 in range(it,it2) last elem. pointed will be excluded!
				 // that means now only 4th,5th,6th,7th elements will be spliced!
	list3.splice(list3.begin(),list4,it,it2);
	for(auto x: list3){cout<<x<<' ';}cout<<"\n";
	for(auto x: list4){cout<<x<<' ';}cout<<"\n\n";

// thats all abt sharing or splicing elem. in list!
// to make unique elements!

	FOR(4)list1.push_back(34); //4 - 34's are added into list1
for(auto x: list1)cout<<x<<' ';cout<<"\n\n";
	list1.unique();
	for(auto x: list1)cout<<x<<' ';cout<<"\n\n";


list<double> list = { 2.55, 3.15, 4.16, 4.16,
                          4.77, 12.65, 12.65, 13.59 };
for(auto x: list)cout<<x<<' ';cout<<"\n\n";
	list.unique(compare); //this user defined compare function will makesure that unique integral part!
	for(auto x: list)cout<<x<<' ';cout<<"\n\n";

auto it3 = list.begin();advance(it3,4);
auto itr = list.emplace(it3,51.8); //inserts the element at the poition where it3 is pointing!! here-4th position
								  //returns the same poisition iterator!! //here - 4thposition!
list.emplace(itr,7.9); // itr - 4th position!
for(auto x: list)cout<<x<<' ';cout<<"\n\n";

// you can merge two lists too! using a user-defined function like compare in unique!!
*/

/*
  ______ _______ _______ ______ 
 / _____|_______|_______) _____)
( (____  _____      _  ( (____  
 \____ \|  ___)    | |  \____ \ 
 _____) ) |_____   | |  _____) )
(______/|_______)  |_| (______/ 
                                
*/
    


    #ifndef ONLINE_JUDGE
    cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    #endif
}