        #include <cmrc/cmrc.hpp>
#include <map>
#include <utility>

namespace cmrc {
namespace togiapp {

namespace res_chars {
// These are the files which are available in this resource library
// Pointers to resources/logo.png
extern const char* const f_a3e6_resources_logo_png_begin;
extern const char* const f_a3e6_resources_logo_png_end;
}

namespace {

const cmrc::detail::index_type&
get_root_index() {
    static cmrc::detail::directory root_directory_;
    static cmrc::detail::file_or_directory root_directory_fod{root_directory_};
    static cmrc::detail::index_type root_index;
    root_index.emplace("", &root_directory_fod);
    struct dir_inl {
        class cmrc::detail::directory& directory;
    };
    dir_inl root_directory_dir{root_directory_};
    (void)root_directory_dir;
    static auto f_55b5_resources_dir = root_directory_dir.directory.add_subdir("resources");
    root_index.emplace("resources", &f_55b5_resources_dir.index_entry);
    root_index.emplace(
        "resources/logo.png",
        f_55b5_resources_dir.directory.add_file(
            "logo.png",
            res_chars::f_a3e6_resources_logo_png_begin,
            res_chars::f_a3e6_resources_logo_png_end
        )
    );
    return root_index;
}

}

cmrc::embedded_filesystem get_filesystem() {
    static auto& index = get_root_index();
    return cmrc::embedded_filesystem{index};
}

} // togiapp
} // cmrc
    