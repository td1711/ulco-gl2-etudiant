{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
  name = "broadcast";

  src = ./. ;

  buildInputs = with pkgs; [
    cmake
    libhv
  ];

  shellHook = ''
    echo ${pkgs.libhv}
  '';

}

