pipeline{
    agent any

    environment{
        CMAKE_BIN = 'cmake'
        CTEST_BIN = 'ctest'
    }

    stages{

        stage('Checkout Code'){
            steps{
                checkout scm
            }

        }

        stage('Configure and Build'){
            steps{
                sh "${CMAKE_BIN} -S . -B build"
                sh "${CMAKE_BIN} --build build -j $(nproc || sysctl -n hw.ncpu)"
            }
        }

        stage('Test'){
            steps{
                sh "${CTEST_BIN}  --test-dir build --output-on-failure"
            }
        }

        stage('Documentation'){
            steps{
                sh "${CMAKE_BIN} --build build --target doc"
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