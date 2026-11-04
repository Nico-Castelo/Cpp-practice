    #pragma once
    #include <string>
    #include <unordered_map>

    struct Attribute
    {
        float Base = 0.0f;
        float Modifier = 0.0f;
        float GetValue() const { return Base + Modifier; }
    };

    class Stats
    {
    public:
        Attribute* GetAttribute(const std::string& name) const;

    private:
        std::unordered_map<std::string, Attribute*> Attributes;
    };
