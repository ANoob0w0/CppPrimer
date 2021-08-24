#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

//remove the puncts
inline void punctRemove(std::string &word)
{
    for (auto it = word.begin(); it != word.end();)
    {
        if (ispunct(*it))
            it = word.erase(it);
        else
            ++it;
    }
}

std::string make_plural(const std::size_t &ctr, const std::string &s1, const std::string &s2)
{
    return (ctr > 1) ? s1 : s1 + s2;
}

class QueryResult;
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    std::ostream &query(std::ostream &, const std::string &) const;
    QueryResult query(const std::string &) const;
    ~TextQuery(){};

private:
    std::shared_ptr<std::vector<std::string>> text;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
};

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> t) : sought(s), lines(p), text(t){};

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> text;
};

TextQuery::TextQuery(std::ifstream &ifs)
    : text(new std::vector<std::string>)
{
    std::string line;
    while (std::getline(ifs, line))
    {
        text->push_back(line);
        line_no lineNum = text->size() - 1;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            punctRemove(word);
            auto &ret = word_map[word];
            if (!ret)
                ret.reset(new std::set<line_no>);
            ret->insert(lineNum);
        }
    }
}

std::ostream &TextQuery::query(std::ostream &os, const std::string &word) const
{
    auto ret = word_map.find(word);
    if (ret != word_map.end())
    {
        std::string t = " time";
        if (ret->second->size() > 1)
            t = " times";
        os << word << " occurs " << ret->second->size() << t << std::endl;
        for (auto &l : *ret->second)
        {
            os << "(line " << l << ") " << (*text)[l] << std::endl;
        }
    }
    else
        os << "find nothing:(" << std::endl;
    return os;
}

QueryResult TextQuery::query(const std::string &word) const
{
    static std::shared_ptr<std::set<TextQuery::line_no>> nodata;
    auto loc = word_map.find(word);
    if (loc == word_map.end())
        return QueryResult(word, nodata, text);
    else
        return QueryResult(word, loc->second, text);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto &num : *qr.lines)
        os << "\t(line " << num + 1 << ") "
           << *(qr.text->begin() + num) << std::endl;
    return os;
}