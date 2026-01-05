pipeline{
    agent any

    environment{
        CMAKE_BIN = '/opt/homebrew/bin/cmake'
        CTEST_BIN = '/opt/homebrew/bin/ctest'
    }

    tools {
        cmake 'default'
    }

    stages{

        stage('Checkout Code'){
            steps{
                checkout scm
            }

        }

        stage('Configure and Build'){
            steps{
                sh "cmake -S . -B build"
                sh "cmake--build build -j 4"
            }
        }

        stage('Test'){
            steps{
                script{
                    def cmakePath = tool name: 'default', type: 'cmake'
                    sh "${cmakePath}/bin/ctest  --test-dir build --output-on-failure"
                }

            }
        }

        stage('Documentation'){
            steps{
                sh "cmake --build build --target doc"
            }
        }
    }

    post {
        success{
            echo 'Build and Tests successful!'
            archiveArtifacts artifacts: 'doc/**', allowEmptyArchive: true
        }
        failure{
            echo 'Build fehlgeschlagen. Übeprüfe die Logs.'
        }
        cleanup {
            sh 'rm -rf build'
        }
    }
}