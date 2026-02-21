# Installation

## Install system packages

### Arch, Manjaro and EndeavourOS based distributions

```sh
pacman -S --noconfirm qt6-base ruby
```

### Debian and Ubuntu based distributions

```sh
apt install -y qt6-base-dev qt6-base-private-dev ruby-dev
```

### RHEL, Fedora and Rocky based distributions

```sh
dnf install -y qt6-qtbase-devel qt6-qtbase-private-devel ruby-devel
```

### Windows with MSYS2

```sh
pacman -S --noconfirm mingw-w64-ucrt-x86_64-qt6-base mingw-w64-ucrt-x86_64-ruby
```

## Install ruby-qt6-qtwidgets gem

### From RubyGems

```sh
gem install ruby-qt6-qtwidgets
```

### From GitHub master branch

Create `Gemfile` like the following:

```ruby
source "https://rubygems.org/"

%w[
  rice
  qtcore qtgui qtwidgets
].each do |lib|
  gem_name = "ruby-qt6-#{lib}"
  git = "https://github.com/souk4711/ruby-qt6.git"
  glob = "#{lib}/#{lib}.gemspec"
  gem gem_name, git:, glob:
end
```

Install these gems by Bundler:

```sh
bundle install
```
