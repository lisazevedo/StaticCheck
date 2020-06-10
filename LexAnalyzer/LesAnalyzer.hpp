
#pragma once
 
class LesAnalyzer  
{
	private:

	public:
		Token T;
		char current_position;
		
		int token_anaLes();
		void token_clear();
		int check_token_size();

		LesAnalyzer();
		~LesAnalyzer();

};