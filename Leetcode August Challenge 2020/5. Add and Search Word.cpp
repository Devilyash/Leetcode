class WordDictionary{
	struct Trienode
	{
		char val; // stored character (1 byte)
		int count; // to count the no of strings with the given prefix (4 bytes)
		int endsHere; // to check if a string is present or not or how many duplicate strings are presnet (4 bytes)
		Trienode* child[26]; // to store all the alphabets pointers (8*26 bytes)
		// total size of one node = 1+4+4+208 = 217 bytes
	};
	Trienode* root;
	
	Trienode* getNode(int index)
	{
		Trienode* newnode = new Trienode;
		newnode->val = 'a' + index;
		newnode->count = newnode->endsHere = 0;
		for(int i=0;i<26;i++)
		{
			newnode->child[i] = NULL;
		}
		return newnode;
	}
	
	public:
		// Constructor to initialise the root node
		WordDictionary()
		{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			root = getNode('/'-'a'); // give slash "/" as the value to the root node
		}
		// Insert function
		void addWord(string word)
		{
			Trienode* curr = root;
			int index;
			for(int i=0; word[i] != '\0'; ++i)
			{
				index = word[i]-'a';
				if(curr->child[index] == NULL)
				{
					curr->child[index] = getNode(index);
				}
				curr->child[index]->count += 1;
				curr = curr->child[index];
			}
			curr->endsHere += 1;
		}
		// Search function
		bool search(string word)
		{
			return searchUtil(word, root);
		}
		// Search Utility
		bool searchUtil(string word, Trienode* node)
		{
			Trienode* curr = node;
			int index;
			for(int i=0; word[i] != '\0'; ++i)
			{
				if(word[i] == '.')
				{
					for(auto ch: curr->child)
                    if(ch && searchUtil(word.substr(i+1), ch)) return true;
                	return false;
				}
				index = word[i]-'a';
				if(curr->child[index] == NULL)
					return false;
				curr = curr->child[index];
			}
			return (curr->endsHere > 0);
		}
};

