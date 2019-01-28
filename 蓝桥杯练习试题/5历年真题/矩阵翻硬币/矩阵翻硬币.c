#include<stdio.h>
#include<math.h>
#include<string.h>
int a[1001],b[1001],len1,len2;
void binary(int *p,int *q,int *tt,int hlen1)
{
   int i,tmp,temp;
   for(i=1;i<hlen1;i++)
	   tt[i+1]=p[i]+q[i];
   for(i=hlen1;i>=2;i--)
      if(tt[i]>9)
	  {
	    tt[i-1]++;
		tt[i]%=10;
	  }
	  tmp = tt[1];
   for(i=2;i<=hlen1;i++)
   {
	   temp = tt[i];
       tt[i]=(tmp*10+tt[i])/2;
       tmp = temp%2;
   }
   for(i=2;i<=hlen1;i++)
	   tt[i-1]=tt[i];
   tt[hlen1]=0;

}
int big(int p[501],int q[1001],int r,int cc)
{
  int tmp[1002]={0},t[501]={0},i,j,tt;
  for(i=0;i<r;i++)
    t[i]=p[r-1-i];
  for(i=0;i<r;i++)
    for(j=0;j<r;j++)
      tmp[i+j]=tmp[i+j]+t[i]*t[j];
  //处理进位
  for(i=0;i<r+r;i++)
     if(tmp[i]>9)
      {tmp[i+1]+=tmp[i]/10;tmp[i]%=10;}


  for(i=1001;i>=0;i--)
    if(tmp[i]!=0)
	 {tt=i;break;}
  if(cc==0)
  {
      if(tt==len1-1)
      {
         	 for(i=0;i<len1;i++)
	     {
		    if(tmp[len1-1-i]==q[i])
		       continue;
	        else if(tmp[len1-1-i]>q[i])
	           return 0;
		    else return 1;
	     }
	      return 1;
      }
      else if(tt>len1-1)
        return 0;
      else
        return 1;

  }
  else
  {
     if(tt==len2-1)
     {
           		 for(i=0;i<len2;i++)
	     	 {
			  if(tmp[len2-1-i]==q[i])
			    continue;
		      else if(tmp[len2-1-i]>q[i])
		        return 0;
			  else return 1;
		     }
		     return 1;
     }
     else if(tt>len2-1)
        return 0;
     else
        return 1;
  }

}
int equal(int p[501],int q[501],int r,int cc)
{
	int i,j,t[501]={0},s[501]={0},tmp[1001]={0},tmp2[1001]={0},kk,tt;
   if(cc==0)
   {
     for(i=0;i<r;i++)
	 {
	   t[i]=p[r-1-i];
	   s[i]=q[r-1-i];
	 }

	 for(i=0;i<r;i++)
		 for(j=0;j<r;j++)
		 {
		    tmp[i+j]=tmp[i+j]+t[i]*t[j];
			tmp2[i+j]=tmp2[i+j]+s[i]*s[j];
		 }
	for(i=0;i<r*2;i++)
	{
	   if(tmp[i]>9)
	   {
	     tmp[i+1]+=tmp[i]/10;
		 tmp[i]%=10;
	   }
	   if(tmp2[i]>9)
	   {
	     tmp2[i+1]+=tmp2[i]/10;
		 tmp2[i]%=10;
	   }
	}

    for(i=r+r;i>=0;i--)
      if(tmp[i]!=0)
      {kk=i;break;}
    for(i=r+r;i>=0;i--)
      if(tmp2[i]!=0)
      {tt=i;break;}

	//直接比
    if(kk!=len1-1||tt!=len1-1)
    {
        if(kk!=len1-1)
        {
             for(i=0;i<len1;i++)
        	{
         	  if(tmp2[len1-1-i]==a[i])
	         	  continue;
              else if(tmp2[len1-1-i]>a[i])
	            return 1;
	          else
	            return 0;
        	}
        	return 1;
        }
        else
        {
           for(i=0;i<len1;i++)
           {
             if(tmp[len1-1-i]==a[i])
               continue;
       	     else if(tmp[len1-1-i]>a[i])
	            return 0;
	         else
	            return 1;
           }
           return 0;
        }
    }
    else
    {
        kk=0;tt=0;
     for(i=0;i<len1;i++)
	 {
	   if(tmp[len1-1-i]==a[i])
		   continue;
	   else if(tmp[len1-1-i]>a[i])
	   {kk=1;break;}
	   else
	   {kk=2;break;}
	 }
	for(i=0;i<len1;i++)
	{
	  if(tmp2[len1-1-i]==a[i])
		  continue;
	  else if(tmp2[len1-1-i]>a[i])
	  {tt=1;break;}
	  else
	  {tt=2;break;}
	}
    if(kk==2&&tt==1)
		return 1;
	else return 0;
    }
   }
   else
   {
         for(i=0;i<r;i++)
	 {
	   t[i]=p[r-1-i];
	   s[i]=q[r-1-i];
	 }

	 for(i=0;i<r;i++)
		 for(j=0;j<r;j++)
		 {
		    tmp[i+j]=tmp[i+j]+t[i]*t[j];
			tmp2[i+j]=tmp2[i+j]+s[i]*s[j];
		 }
	for(i=0;i<r*2;i++)
	{
	   if(tmp[i]>9)
	   {
	     tmp[i+1]+=tmp[i]/10;
		 tmp[i]%=10;
	   }
	   if(tmp2[i]>9)
	   {
	     tmp2[i+1]+=tmp2[i]/10;
		 tmp2[i]%=10;
	   }
	}
    for(i=r+r;i>=0;i--)
      if(tmp[i]!=0)
      {kk=i;break;}
    for(i=r+r;i>=0;i--)
      if(tmp2[i]!=0)
      {tt=i;break;}

	//直接比
	if(kk!=len2-1||tt!=len2-1)
	{
         	   if(kk!=len2-1)
	        {
	             for(i=0;i<len2;i++)
	        	{
	         	  if(tmp2[len2-1-i]==a[i])
		         	  continue;
	              else if(tmp2[len2-1-i]>a[i])
		            return 1;
		          else
		            return 0;
	        	}
	        	return 1;
	        }
	        else
	        {
	           for(i=0;i<len2;i++)
	           {
	             if(tmp[len2-1-i]==a[i])
	               continue;
	       	     else if(tmp[len2-1-i]>a[i])
		            return 0;
		         else
		            return 1;
	           }
	           return 0;
	        }

    }
    else
	{
	        kk=0;tt=0;
    			for(i=0;i<len2;i++)
			{
			   if(tmp[len2-1-i]==b[i])
				   continue;
			   else if(tmp[len2-1-i]>b[i])
			   {kk=1;break;}
			   else
			   {kk=2;break;}
			}
			for(i=0;i<len2;i++)
			{
			  if(tmp2[len2-1-i]==b[i])
				  continue;
			  else if(tmp2[len2-1-i]>b[i])
			  {tt=1;break;}
			  else
			  {tt=2;break;}
			}
		    if(kk==2&&tt==1)
				return 1;
			else return 0;
    }

   }
}
int xiang(int p[501],int tt[501],int r,int cc)
{
   int sum=0,i;
   if(cc==0)
   {
     for(i=0;i<r;i++)
		 if(p[i]==tt[i])
			 sum++;
	 if(sum==r)
		 return 1;
	 return 0;
   }
	else
   {
     for(i=0;i<r;i++)
		 if(p[i]==tt[i])
			 sum++;
	 if(sum==r)
		 return 1;
	 return 0;
   }
}
int special(int p[501],int cc)
{
      int r,tmp[1002]={0},t[501]={0},i,j,sum,tt;
  if(cc==0)
      r = (len1+1)/2;
  else
      r = (len2+1)/2;
  for(i=0;i<r;i++)
    t[i]=p[r-1-i];
  for(i=0;i<r;i++)
    for(j=0;j<r;j++)
      tmp[i+j]=tmp[i+j]+t[i]*t[j];
  //处理进位
  for(i=0;i<r+r;i++)
     if(tmp[i]>9)
      {tmp[i+1]+=tmp[i]/10;tmp[i]%=10;}
  for(i=r+r;i>=0;i--)
    if(tmp[i]!=0)
      {tt=i;break;}
  sum=0;
  if(cc==0)
   {
     if(tt!=len1-1)
       return 0;
     else
     {
       for(i=0;i<=tt;i++)
          if(tmp[i]==a[len1-1-i])
            sum++;
       if(sum==len1)
         return 1;
       else
         return 0;
     }
   }
  else
  {
     if(tt!=len2-1)
       return 0;
     else
     {
          for(i=0;i<=tt;i++)
          if(tmp[i]==b[len2-1-i])
             sum++;
       if(sum==len2)
         return 1;
       else
         return 0;
     }
  }
}
void sqr()
{
     int hlen1,hlen2,i,j,temp[1001]={0},tt[501]={0},p[501]={0},q[501]={0},ttt;
    int s[501]={0},sk[501]={0};
    hlen1 = (len1+1)/2;
    hlen2 = (len2+1)/2;
    if(len1%2==1)
    {tt[0]=(int)sqrt(a[0]);p[0]=(int)sqrt(a[0]);q[0]=(int)sqrt(a[0]);}
  else
    {tt[0]=(int)sqrt(a[0]*10+a[1]);p[0]=(int)sqrt(a[0]*10+a[1]);q[0]=(int)sqrt(a[0]*10+a[1]);}

  for(i=1;i<hlen1;i++)
    p[i]=0;
  for(i=1;i<hlen1;i++)
    q[i]=9;
  while(equal(p,q,hlen1,0))
  {
    binary(p,q,tt,hlen1);
	if(xiang(p,tt,hlen1,0))
		break;
	if(big(tt,a,hlen1,0))
		for(i=0;i<hlen1;i++)
			p[i]=tt[i];
	else
		for(i=0;i<hlen1;i++)
			q[i]=tt[i];
	
	for(i=1;i<501;i++)
		tt[i]=0;
  }

  if(special(q,0))
    for(i=0;i<hlen1;i++)
      s[i]=q[i];
  else
  for(i=0;i<hlen1;i++)
		s[i]=p[i];
 if(len2%2==1)
    {tt[0]=(int)sqrt(b[0]);p[0]=(int)sqrt(b[0]);q[0]=(int)sqrt(b[0]);}
  else
    {tt[0]=(int)sqrt(b[0]*10+b[1]);p[0]=(int)sqrt(b[0]*10+b[1]);q[0]=(int)sqrt(b[0]*10+b[1]);}
  for(i=1;i<hlen2;i++)
    p[i]=0;
  for(i=1;i<hlen2;i++)
    q[i]=9;
  for(i=1;i<501;i++)
	  tt[i]=0;
  while(equal(p,q,hlen2,1))
  {
    binary(p,q,tt,hlen2);
	if(xiang(p,tt,hlen2,1))
		break;
	if(big(tt,b,hlen2,1))
		for(i=0;i<hlen2;i++)
			p[i]=tt[i];
	else
		for(i=0;i<hlen2;i++)
			q[i]=tt[i];
	
	for(i=1;i<501;i++)
		tt[i]=0;
  }

   if(special(q,1))
    for(i=0;i<hlen2;i++)
      sk[i]=q[i];
   else
   for(i=0;i<hlen2;i++)
		 sk[i]=p[i];
	
   /*for(i=0;i<hlen1;i++)
      printf("%d",s[i]);
   printf("\n");
   for(i=0;i<hlen2;i++)
      printf("%d",sk[i]);
   printf("\n");
   */
   for(i=0;i<hlen1/2;i++)
   {
	   ttt = s[i];
	   s[i]=s[hlen1-1-i];
	   s[hlen1-1-i]=ttt;
   }
	
   for(i=0;i<hlen2/2;i++)
   {
       ttt = sk[i];
	   sk[i]=sk[hlen2-1-i];
	   sk[hlen2-1-i]=ttt;
   }
  for(i=0;i<hlen1;i++)
    for(j=0;j<hlen2;j++)
      	temp[i+j]+=s[i]*sk[j];
  for(i=0;i<hlen1+hlen2;i++)
	  if(temp[i]>9)
	  {
	     temp[i+1]+=temp[i]/10;
		 temp[i]%=10;
	  }	
  //printf("%d\n",hlen1+hlen2);
  for(j=hlen1+hlen2;j>=0;j--)
	  if(temp[j]!=0)
		  break;
  for(i=j;i>=0;i--)
    printf("%d",temp[i]);
  printf("\n");
  		


}
int main()
{
   int i;
  char n[1001],m[1001];
  scanf("%s",n);
  scanf("%s",m);
  len1=strlen(n);
  len2=strlen(m);
  for(i=0;i<len1;i++)
    a[i]=n[i]-48;
  for(i=0;i<len2;i++)
    b[i]=m[i]-48;
  sqr();
  return 0;
}