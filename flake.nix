{
  description = "Flake shell";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs =
    { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShellNoCC {
          packages = [
            pkgs.qmk
            pkgs.pyright
            pkgs.ruff-lsp
            pkgs.ruff
            pkgs.llvmPackages_18.clang-tools
            pkgs.python312Packages.venvShellHook
          ];
          shellHook = ''
            unset NIX_CFLAGS_COMPILE
          '';
          venvDir = "venv";
        };
      }
    );
}
