#include <Geode/Geode.hpp>
#include <Geode/modify/MusicDownloadManager.hpp>

class $modify(MusicDownloadManager) {
    gd::string pathForSong(int p0) {
        gd::string path = MusicDownloadManager::pathForSong(p0);

        const char* extensions[] = { ".mp3", ".ogg", ".wav", ".flac", ".aiff", ".aac" };

        for (const char* ext : extensions) {
            gd::string testPath = path;
            size_t dotPos = testPath.find_last_of('.');
            if (dotPos != gd::string::npos) testPath.replace(dotPos, testPath.length() - dotPos, ext);
            else testPath += ext;

            if (std::filesystem::exists(testPath)) return testPath;
        }

        return path;
    }
};