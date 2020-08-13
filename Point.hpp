class Point{
	private :
		double x;
		double y;
	
	public:
		Point(){}
		
		Point(double x, double y){
			this.x = x;
			this.y = y;
		}
		
		void show(){
			std:: cout << "x = " << x << ", y = " << y << std:: endl; 
		}
		
		setCoordinates (double x, double y){
			this.x = x;
			this.y = y;
		}
		
};
