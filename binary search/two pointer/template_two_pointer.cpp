{
// take two pointer
int head=-1,tail=0;
// data structure is used
int cnt=0; // ye main krega window ki proprety ko
// ans
int ans=0;
while(tail<n){
    // eat as many as element as possible
    //and ke badd here we write the window proprety to maintain
    while(head+1<n && (arr[head+1]==1||cnt<k)  ){
        head++;
        if(arr[head]==0) cnt++;
    }
    // save the current best length for this tail
    int len=head-tail+1;

    // update the ans
    ans=max(ans,len);

    // move tail one step forward means window ko ek step agge slide kr do
    if(tail<=head){
        if(arr[tail]==0) cnt--;
        tail++;
    }else{  // when empty
     tail++;
     head=tail-1;  // set window as 0 length 

    }
}
cout<<ans<<endl;
}
