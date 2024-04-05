{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
  name = "chat";

  src = ./. ;

  buildInputs = with pkgs; [
    cmake
    gtkmm3
    libhv
    pkg-config
  ];

  shellHook = ''
    echo ${pkgs.libhv}
  '';

}

