#include <filesystem>
#include <string>

const struct {
    const int width = 60;
    const int height = 20;
    
    const std::filesystem::path root_path = std::filesystem::current_path();
    const std::filesystem::path media_path = root_path / "media";

    
} Context;
