#include<bits/stdc++.h>

usingnamespace std;

constcharnl = '\n';

  typedeflonglongll;

  typedeflongdoubleld;

usingi64 = unsignedlonglong;

usingi32 = unsigned;

usingi128 = unsigned__int128;

  #defineall(x) (x).begin(), (x).end()

voidsolve(){

    intn;

    strings;

    cin>>n>>s;

   vector<pair<int,char>> a(3);

a[0].first = count(all(s),'T');

a[1].first = count(all(s),'I');

a[2].first = count(all(s),'L');

a[0].second = 'T';

a[1].second = 'I';

a[2].second = 'L';

if(a[0].first==a[1].first && a[1].first==a[2].first){

cout<<0<<nl;

return;

}

sort(all(a),greater());

intx = a[0].first,y = a[1].first,z = a[2].first;

if((x==0 && y==0) || (x==0 && z==0 ) || (y==0 && z==0) ){

    cout<<-1<<nl;

    return;

}

inte = 2*x-y-z;

vector`<int>` cnt(n);

for(inti = 0;i<n;i++){

    if(s[i]==a[0].second) cnt[i] = 0;

    elseif(s[i]==a[1].second) cnt[i] = 1;

    elsecnt[i] = 2;

}

vector`<int>` ans;

inti;

for( i = 0;i<n;i++){

    if((cnt[i]==0 && cnt[i+1]!=0) || (cnt[i]!=0 && cnt[i+1]==0)) break;

}

i++;

intk = 0;

if(cnt[i-1]==0){

while(a[0].first>a[1].first){

ans.push_back(i);

ans.push_back(i);

k+=2;

a[1].first++;

a[2].first++;

}

}

elseif(cnt[i]==0){

    while(a[0].first>a[1].first){

    ans.push_back(i+k);

    ans.push_back(i+k+1);

    k+=2;

    a[1].first++;

    a[2].first++;

    }

}

if(cnt[i]==1){

    ans.push_back(i);

    k++;

}

for(;i<n;i++){

    if((cnt[i]==0 && cnt[i+1]==1) || (cnt[i]==1 && cnt[i+1]==0)){

    ans.push_back(i+1+k);

    k++;

    }

}

if(ans.size() <e)

{

    cout<<-1<<nl;

    return;

}

else{

    cout<<e<<nl;

    for(i = 0;i<e;i++){

cout<<ans[i]<<nl;

    }

}

}

intmain(){

ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

intt = 1;

cin>>t;

while(t--){

    solve();

}

    return0;

}
