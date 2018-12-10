
namespace dtl{

  namespace list{

    template<typename T>
    class deList
    {
    public:
      static deList* head;
      T identifier;
      deList* nextP;
      deList* prevP;


    deList(T n, deList* nextT=nullptr, deList* prevT=nullptr): identifier(n){
        nextP=this;
        prevP=this;
      };

      void addNext(deList* elem)
      {
        elem->nextP=this->nextP;
        elem->prevP=this;
        this->nextP->prevP=elem;
        this->nextP=elem;

      }
      __attribute__((warn_unused_result)) deList* removeElem()
      {
        if (prevP==this && nextP==this)
          return this;
        prevP->nextP=nextP;
        nextP->prevP=prevP;
        return this;
      }

      deList* advanceN(int n)
      {
        if (n==0)
          return this;
        else if (n>0 && nextP!=nullptr)
          return nextP->advanceN(n-1);
        else if (n<0)
          return this->retreatN(-n);


      }

      deList* retreatN(int n)
      {
        if (n==0)
          return this;
        else if (n>0 && prevP!=nullptr)
          return prevP->retreatN(n-1);
        else if (n<0)
          return this->advanceN(-n);

      }

    };
  }
}
