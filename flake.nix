{
  description = "Flake shell";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/24.05";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs =
    { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShellNoCC { packages = [ pkgs.qmk ]; };
      }
    );
}
