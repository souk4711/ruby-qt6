# Installation

## Install system packages

### Arch, Manjaro and EndeavourOS based distributions

```sh
pacman -S --noconfirm qtcreator ruby libyaml
```

### Debian and Ubuntu based distributions

```sh
apt install -y qtcreator qt6-base-dev qt6-base-private-dev qt6-declarative-dev ruby-dev libyaml-dev
```

### RHEL, Fedora and Rocky based distributions

```sh
dnf install -y qt-creator qt6-qtbase-devel qt6-qtbase-private-devel qt6-qtdeclarative-devel ruby-devel libyaml-devel
```

## Install ruby-qt6 gem

### From RubyGems

```sh
gem install ruby-qt6
```
