
string findSemicolon(string word, int i, int j)
{
public:
	while (objectString[i][j] != ';') word += objectString[i][j++]; j++;
	return word;
}