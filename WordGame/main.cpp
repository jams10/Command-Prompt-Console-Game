#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <random>
#include <algorithm> // min 함수 사용
#include <cctype> // tolower 함수 사용

// 문자열 벡터에 해당 단어가 있는지 여부를 리턴.
bool contains_word( const std::vector<std::string>& vec, const std::string& word )
{
    for( const auto& w : vec )
    {
        if( w == word )
        {
            return true;
        }
    }
    return false;
}

// 두 벡터에 들어 있는 단어 중 공통 단어들을 담은 벡터를 리턴하는 함수.
std::vector<std::string> get_intersection( const std::vector<std::string>& vec1, 
                                           const std::vector<std::string>& vec2 )
{
    std::vector<std::string> intersection;

    for( const auto& s: vec1 )
    {
        if( contains_word( vec2, s ) )
        {
            intersection.push_back( s );
        }
    }

    return intersection;
}

// 단어의 알파벳 문자 개수 체크.
std::vector<int> fill_buckets( const std::string& word )
{
    std::vector<int> buckets( 26, 0 );
    for( char c : word )
    {
        buckets[c - 'a']++;
    }
    return buckets;
}
// 점수 계산 함수.
int calc_score( const std::string& word1, const std::string& word2 )
{
    const auto buckets1 = fill_buckets(word1);
    const auto buckets2 = fill_buckets(word2);

    int score = 0;
    // 1. 위치는 다르지만 비교할 단어에 같은 문자가 있는 경우.
    for(int i = 0; i < 26; ++i )
    {
        score += std::min(buckets1[i], buckets2[i]);
    }
    // 2. 같은 문자이면서 같은 위치에 있는 경우.
    for(int i = 0; i < 5; i++)
    {
        if(word1[i] == word2[i])
        {
            score++;
        }
    }

    return score;
}

int main()
{
    // 1. 5글자 단어 벡터
    std::vector<std::string> five_letter_words;

    // 스코프를 하나 더 넣어서 벡터에 단어들을 넣은 뒤에, 파일이 닫히도록 함.
    {
        std::ifstream words_file("sgb-words.txt");
    
        // 파일에 있는 단어들을 벡터에 저장.
        for( std::string line; std::getline( words_file, line); )
        {
            if( line.empty() )
            {
                continue;
            }
            five_letter_words.push_back( line );
        }
    }

    // 10k개 자주 사용하는 단어 벡터
    std::vector<std::string> freq_words;

    // 스코프를 하나 더 넣어서 벡터에 단어들을 넣은 뒤에, 파일이 닫히도록 함.
    {
        std::ifstream freq_words_file("10k.txt");
    
        // 파일에 있는 단어들을 벡터에 저장.
        for( std::string line; std::getline( freq_words_file, line); )
        {
            if( line.empty() )
            {
                continue;
            }
            freq_words.push_back( line );
        }
    }
    // freq_words의 사이즈를 조절하여 가장 많이 사용하는 단어 2000 개로 범위를 제한.
    // size를 설정함으로써 게임 난이도 설정 가능.
    freq_words.resize( 100 );

    auto filtered_words = get_intersection( five_letter_words, freq_words );

    // 난수 생성
    std::mt19937 rng( std::random_device{}() );
    std::uniform_int_distribution<int> dist( 0, filtered_words.size() - 1 );

    // 생성된 난수에 따라 한 단어 무작위 선택
    const std::string target = five_letter_words[dist( rng )];

    while( true )
    {
        std::cout << "Guess a five letter word : ";
        std::string guess;
        std::getline( std::cin, guess );

        // 대소문자 상관 없이 문자를 찾도록 모든 문자를 소문자로 바꿈.
        for( auto& c : guess )
        {
            c = std::tolower(c);
        }

        if( guess.size() != 5 )
        {
            std::cout << "Type FIVE letter word!!!!!!!!" << std::endl;
            continue;
        }

        if( !contains_word( five_letter_words, guess ))
        {
            std::cout << "\"" << guess << "\"" <<" is not a word!!!" << std::endl;
            continue;
        }

        const int score = calc_score( guess, target );
        if(score == 10)
        {
            std::cout << "You won human." << std::endl;
            break; 
        }
        else
        {
            std::cout << "Huh! ok you got " << score << " human." << std::endl;
            continue;
        }
        
    }

    return 0;
}