
/*************
 Driver program to test below functions
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
****************/

class Polynomial {

    // Complete the class
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity ;
    
    Polynomial(){
    	degCoeff = new int[10];
        capacity = 10;
        for(int i = 0;i<10;i++){
            degCoeff[i] = 0;
        }        
    }
    Polynomial(Polynomial const &f){
        capacity = f.capacity;
    	degCoeff = new int[capacity];
        //capacity = 10;
        for(int i = 0;i<capacity;i++){
            degCoeff[i] = f.degCoeff[i];
        }        
    }
    void operator=(Polynomial const &f){
        delete [] degCoeff;
        capacity = f.capacity;
    	degCoeff = new int[capacity];
        //capacity = 10;
        for(int i = 0;i<capacity;i++){
            degCoeff[i] = f.degCoeff[i];
        }        
    }
    

    void  setCoefficient(int degree,int coeff){
        if(degree>=capacity){
            capacity = capacity * 2;
           //degree] = coeff;
           setCoefficient(degree,coeff);
        }
        else{
            degCoeff[degree] = coeff;
        }
    }
    
    Polynomial operator+(Polynomial const &f){
        Polynomial fNew;
    	if(capacity>f.capacity){
            fNew.capacity = capacity;
        }
        else{
            fNew.capacity = f.capacity;
        }
        
        for(int i = 0; i<fNew.capacity;i++){
            fNew.degCoeff[i] = degCoeff[i] + f.degCoeff[i];
        }
        //fNew.degCoeff = fNew.Arr[];
        return fNew;
    }
        
    Polynomial operator-(Polynomial const &f){
        Polynomial fNew;
    	if(capacity>f.capacity){
            fNew.capacity = capacity;
        }

        else{
            fNew.capacity = f.capacity;
        }
        
        for(int i = 0; i<fNew.capacity;i++){
            fNew.degCoeff[i] = degCoeff[i] - f.degCoeff[i];
        }
       // fNew.degCoeff = fNew.Arr[];
        return fNew;
    }
    
    
	Polynomial operator*(Polynomial const &f){
        Polynomial fNew;
    	if(capacity>f.capacity){
            fNew.capacity = capacity;
        }
        else{
            fNew.capacity = f.capacity;
        }
        
        for(int i = 0; i<fNew.capacity;i++){
           // fNew.degCoeff[i] = degCoeff[i] - f.degCoeff[i];
            for(int j =0;j<fNew.capacity;j++){
                fNew.degCoeff[i] = degCoeff[i] + f.degCoeff[i];  
            }
        }
       // fNew.degCoeff = fNew.Arr[];
        return fNew;
    }
    
    void print(){
        for(int i = 0;i<capacity;i++){
            if(degCoeff[i]!=0)
                cout<<degCoeff[i]<<"x"<<i<<" ";
        }
       // cout<<endl;
    }
    
    
    
};
