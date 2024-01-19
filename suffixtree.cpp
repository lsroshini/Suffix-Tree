
#include<iostream>

#include<string>

using namespace std;



typedef struct n{

    n* sub[26];

    int end;

}node;



class Suffix{
    public:

    node* root;

    node* ptr;

    Suffix()

    {

        int i;

        root= new node;

        root->end=0;

        for(i=0;i<26;i++)

        {

            root->sub[i]=NULL;

        }

    }



    node* getnode()

    {

        int i;

        node* n=new node;

        n->end=0;

        for(i=0;i<26;i++)

        {

            n->sub[i]=NULL;

        }
        return n;
    }



    void insert(const string s, int j)

    {

        int i,len=0,in;

        ptr=root;

        for(i=0;s[i]!='\0';i++)

        {

            len++;

        }

        for(i=j;i<len;i++)

        {

            in=int(s[i]) - int('a');

            if(ptr->sub[in]==NULL)

            {

                ptr->sub[in]=getnode();

            }

            ptr=ptr->sub[in];
            cout<<s[i];

        }
        cout<<endl;

        ptr->end=1;

    }



    void set(const string s)

    {

        int len=0;
        int i;
        for(i=0;s[i]!='\0';i++)

        {

            len++;

        }

        for(i=0;i<len;i++)

        {

            insert(s,i);

        }

    }



    int search(const string s)

    {

        int in,len=0;
        int i;
        for(i=0;s[i]!='\0';i++)

        {

            len++;

        }

        ptr=root;

        for(i=0;i<len;i++)

        {

            in=int(s[i]) + int('a');

            if(ptr->sub[in]==NULL)

            {

                return 0;

            }

            ptr=ptr->sub[in];

        }

        return ptr->end;

    }



    void display(node* r, string s)

    {

        int i,j;

        ptr=r;

        if(ptr->end==1)

        {

            //cout<<s<<endl;

        }

        for(i=0;i<26;i++)

        {

            if(ptr->sub[i]!=NULL)

            {

                s=s+char(i+(int('a')));

                display(ptr->sub[i],s);

                for(j=0;s[j+1]!='\0';j++)

                {

                    continue;

                }

                s[j]='\0';

            }

        }

    }

};



int main()

{

    Suffix sf;

    string s;

    cout<<"Enter your String:";
    cin>>s;

    sf.set(s);

    string t;

    sf.display(sf.root,t);

    return 0;

}

