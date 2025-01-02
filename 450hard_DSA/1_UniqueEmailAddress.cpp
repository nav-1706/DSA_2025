class Solution {
public:

    unordered_set<string>unique;

    int numUniqueEmails(vector<string>& emails) {
        
        for(int k=0; k<emails.size(); k++){

            auto email = emails[k];
            string process_email = "";
            
            int i = 0;
            while(email[i] != '@'){

                if(email[i] == '.'){
                    i++;
                    continue;
                }

                else if(email[i] == '+'){

                    while(email[i] != '@') i++;
                }
                
                else{
                    process_email.push_back(email[i]);
                    i++;
                }
            }

            while(i < email.length()){
                process_email.push_back(email[i]);
                i++;
            }

            unique.insert(process_email);
        }

        for(auto e: unique) cout<<e<<" ";

        return unique.size();
    }
};